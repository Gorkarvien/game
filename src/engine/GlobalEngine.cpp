#include "GlobalEngine.h"
#include "GraphicsEngine.h"
#include "GameEngine.h"
#include <SFML/System.hpp>

namespace engine
{
  int main_routine()
  {
    
    bool stop = false;
    sf::Clock clock; 
    sf::Time elapsed_time;
    Graphics* graphics_engine = new Graphics();
    sf::RenderWindow *window = graphics_engine->render_window();
    while(true)
    {
      sf::Event event;
      while(window->pollEvent(event))
      {
	if(event.type == sf::Event::Closed)
	  window->close();
      }
      
      if(!window->isOpen() || stop)
      {
	break;
      }
      elapsed_time = clock.restart();
      if(elapsed_time.asSeconds() < 1.f / MAXFPS)
      {
	sf::sleep(sf::seconds(1.f / MAXFPS - elapsed_time.asSeconds()));
	elapsed_time = sf::seconds(1.f / MAXFPS);
      }
      
      update_game(elapsed_time);
      
      graphics_engine->draw();
    }
    delete graphics_engine;
    return 0;
  }
}