#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <queue>
#include <vector>

#include "RenderOperation.h"

namespace TFG{
	class GameActor;
}

namespace engine
{
	class Renderable;

  class GraphicsEngine
  {
  protected:
    sf::RenderWindow *window;
	std::priority_queue<RenderOperation, std::vector<RenderOperation>,RenderOperation::comp> m_renderQueue;
	std::vector<Renderable*> m_renderableList;

  public:
     GraphicsEngine();
    ~GraphicsEngine()
    {
      delete window;
    }
    sf::RenderWindow *render_window() {return window;}

	void registerRenderable(Renderable&);
	void notifyRenderable(sf::Time);
	
	void render(sf::Time);
	void addToRenderQueue (sf::Drawable& _asset, unsigned short int _zbuf);
  };
}

#endif
