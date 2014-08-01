#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

#include <SFML/Graphics.hpp>

namespace engine
{



  class GraphicsEngine
  {
  protected:
    sf::RenderWindow *window;

  public:
      GraphicsEngine();
      static GraphicsEngine* CreateGraphicsEngine();
    ~GraphicsEngine()
    {
      delete window;
    }
    int update();
    sf::RenderWindow *render_window() {return window;}
  };
}

#endif
