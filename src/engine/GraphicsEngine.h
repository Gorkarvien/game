#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#include <SFML/Graphics.hpp>

namespace engine
{
  class Graphics
  {
  protected:
    sf::RenderWindow *window;
    
  public:
    Graphics();
    ~Graphics()
    {
      delete window;
    }
    int draw();
    sf::RenderWindow *render_window() {return window;}
  };
}

#endif
