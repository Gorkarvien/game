#include "GraphicsEngine.h"

namespace engine
{
  GraphicsEngine::GraphicsEngine()
  {
    window = new sf::RenderWindow(sf::VideoMode(800,600), "the game port : XXXX");
  }
  
  int GraphicsEngine::update()
  {
    window->clear();
    // tmp
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    // end tmp
    window->draw(shape);
    window->display();
    return 0;
  }
}
