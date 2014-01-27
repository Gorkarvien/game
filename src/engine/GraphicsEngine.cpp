#include "GraphicsEngine.h"

namespace engine
{
  Graphics::Graphics()
  {
    window = new sf::RenderWindow(sf::VideoMode(200,200), "SFML works !");
  }
  
  int Graphics::draw()
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