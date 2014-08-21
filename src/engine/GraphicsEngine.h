#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

#include <SFML/Graphics.hpp>

namespace TFG{
	class GameActor;
}

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
    int update(TFG::GameActor& bob);
    sf::RenderWindow *render_window() {return window;}
  };
}

#endif
