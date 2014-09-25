#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

#include <SFML/Graphics.hpp>
#include <queue>
#include <vector>

#include "RenderOperation.h"

namespace TFG{
	class GameActor;
}

namespace engine
{
	class Rendable;

  class GraphicsEngine
  {
  protected:
    sf::RenderWindow *window;
	std::priority_queue<RenderOperation, std::vector<RenderOperation>,RenderOperation::comp> m_renderQueue;
	std::vector<Rendable*> m_RendableList;

  public:
      GraphicsEngine();
      static GraphicsEngine* CreateGraphicsEngine();
    ~GraphicsEngine()
    {
      delete window;
    }
    int update(const TFG::GameActor& bob);
    sf::RenderWindow *render_window() {return window;}

	void addToRenderQueue (sf::Drawable& _asset, unsigned short int _zbuf);
  };
}

#endif
