#include "GameEngine.h"
#include "GraphicsEngine.h"
#include "GameplayEngine.h"
#include "InputsEngine.h"
#include "DebugModule.h"
#include <SFML/System.hpp>
#include <iostream>
#include "GameActor.h"


namespace engine
{
	int GameEngine::initialization()
	{
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
	int frameSkiped=0;
	int gameLag=0;//lag beetween real time and game time

    bool stop = false;
    sf::Clock clock;
    sf::Time elapsed_time;
    GraphicsEngine* graphics_engine = new GraphicsEngine();
    sf::RenderWindow *window = graphics_engine->render_window();
    module::DebugModule* debug = new module::DebugModule();
	TFG::GameActor* bob = new TFG::GameActor();
    InputsEngine* inputsEngine = new InputsEngine(*bob); 

	clock.restart();
    while(true)
    {
		elapsed_time = clock.restart();
		frameSkiped = 0;
		gameLag += elapsed_time.asMilliseconds();
        std::cout <<elapsed_time.asMilliseconds() << std::endl;

		processInput(window,inputsEngine);

 		while(gameLag >= MS_PER_UPDATE && frameSkiped < MAX_FRAME_SKIP)
		{
         std::cout << "game_update" << std::endl;
			//update gameplay
			TFG::update(elapsed_time);//???
			bob->update(MS_PER_UPDATE);//move in a game word variable and update in function above?
			frameSkiped ++;
			gameLag-=MS_PER_UPDATE;
		}

		graphics_engine->update(*bob);
		debug->update(elapsed_time);

      //pour empecher un bug de temp d'update nul en ms
	  elapsed_time = clock.getElapsedTime();
      if(elapsed_time.asSeconds() < 1.f / MAXFPS)//if we are too quick
      {
	sf::sleep(sf::seconds(1.f / MAXFPS - elapsed_time.asSeconds()));
	elapsed_time = sf::seconds(1.f / MAXFPS);
      }
//debuginfo...???
       //  std::cout << "render update" << std::endl;

      if(!window->isOpen() || stop)
      {
         std::cout << "shutdown" << std::endl;
	break;
      }
    }
    delete graphics_engine;
    return 0;
  }
}
