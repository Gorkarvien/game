#include "GameEngine.h"
#include "GraphicsEngine.h"
#include "GameplayEngine.h"
#include "InputsEngine.h"
#include "DebugModule.h"
#include <iostream>


namespace engine
{
	int GameEngine::initialization()
	{
		m_graphicsEngine = new GraphicsEngine();
		m_gameplayEngine = new TFG::GameplayEngine();
		m_window = m_graphicsEngine->render_window();
		debug = new module::DebugModule();
		m_inputsEngine = new InputsEngine(m_gameplayEngine->getActor()); 
		
		return 0;
	}
	void GameEngine::processInput(sf::RenderWindow * window,InputsEngine* inputsEngine)
	{

		sf::Event event;
        while(window->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            window->close();
            if(event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) 
            {
				inputsEngine->proceedEvent(event);//todo clean and merge all event or split further
            }
            else if(event.type == sf::Event::MouseMoved|| event.type == sf::Event::MouseButtonPressed ||
               event.type == sf::Event::MouseButtonReleased )
            {
                inputsEngine->proceedEvent(event);
            }
        }
	}

  int GameEngine::main_loop()
  {
	sf::Time elapsed_time;
	int frameSkiped=0;
	int gameLag=0;//lag beetween real time and game time

    bool stop = false;

	m_clock.restart();
    while(true)
    {
		elapsed_time = m_clock.restart();
		frameSkiped = 0;
		gameLag += elapsed_time.asMilliseconds();
       // std::cout <<elapsed_time.asMilliseconds() << std::endl;

		processInput(m_window,m_inputsEngine);

 		while(gameLag >= MS_PER_UPDATE && frameSkiped < MAX_FRAME_SKIP)
		{
         //std::cout << "game_update" << std::endl;
			m_gameplayEngine->update(MS_PER_UPDATE);
			frameSkiped ++;
			gameLag-=MS_PER_UPDATE;
		}
		m_graphicsEngine->update(m_gameplayEngine->getActor());
		//debug->update(elapsed_time);

      //pour empecher un bug de temp d'update nul en ms
	  elapsed_time = m_clock.getElapsedTime();
      if(elapsed_time.asSeconds() < 1.f / MAXFPS)//if we are too quick
      {
	sf::sleep(sf::seconds(1.f / MAXFPS - elapsed_time.asSeconds()));
	elapsed_time = sf::seconds(1.f / MAXFPS);
      }
//debuginfo...???
       //  std::cout << "render update" << std::endl;

      if(!m_window->isOpen() || stop)
      {
         std::cout << "shutdown" << std::endl;
	break;
      }
    }
    delete m_graphicsEngine;
    return 0;
  }
}
