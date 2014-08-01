#include "GameEngine.h"
#include "GraphicsEngine.h"
#include "GameplayEngine.h"
#include "InputsEngine.h"
#include "DebugModule.h"
#include <SFML/System.hpp>


namespace engine
{
	int initialization()
	{
		return 0;
	}

  int main_loop()
  {

    bool stop = false;
    sf::Clock clock;
    sf::Time elapsed_time;
    GraphicsEngine* graphics_engine = new GraphicsEngine();
    InputsEngine* inputsEngine = new InputsEngine();
    sf::RenderWindow *window = graphics_engine->render_window();
    module::DebugModule* debug = new module::DebugModule();
    while(true)
    {
        sf::Event event;
        while(window->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            window->close();
            if(event.type == sf::Event::KeyPressed ||
               event.type == sf::Event::KeyReleased ||
               event.type == sf::Event::MouseMoved||
               event.type == sf::Event::MouseButtonPressed ||
               event.type == sf::Event::MouseButtonReleased )
            {
                inputsEngine->proceedEvent(event);
            }
        }

      if(!window->isOpen() || stop)
      {
	break;
      }
      elapsed_time = clock.restart();
      graphics_engine->update();
      debug->update(elapsed_time);
      //gameplay->update(elapsed_time);

      elapsed_time = clock.getElapsedTime();
      if(elapsed_time.asSeconds() < 1.f / MAXFPS)//if we are too quick
      {
	sf::sleep(sf::seconds(1.f / MAXFPS - elapsed_time.asSeconds()));
	elapsed_time = sf::seconds(1.f / MAXFPS);
      }
//debuginfo...???


    }
    delete graphics_engine;
    return 0;
  }
}
