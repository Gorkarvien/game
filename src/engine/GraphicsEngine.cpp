#include "GraphicsEngine.h"
#include "GameActor.h"
#include "Renderable.h"
#include "GraphicsEngine.h"

namespace engine
{
  GraphicsEngine::GraphicsEngine()
  {
    window = new sf::RenderWindow(sf::VideoMode(800,600), "the game port : XXXX");
  }

  void GraphicsEngine::render(sf::Time _timeSinceGameUpdate)
  {
	  window->clear();
	  this->notifyRenderable(_timeSinceGameUpdate);
	  while(!m_renderQueue.empty())
	  {
		window->draw(*(m_renderQueue.top().m_drawable));
		m_renderQueue.pop();
	  }
	  window->display();
  }

  void GraphicsEngine::registerRenderable(Renderable& _observer)
  {
	  m_renderableList.push_back(&_observer);
  }

  void GraphicsEngine::notifyRenderable(sf::Time _timeSinceGameUpdate)
  {
	  for(std::vector<Renderable*>::iterator it= m_renderableList.begin(); it!=m_renderableList.end(); it++)
	  {
		  (*it)->callToRender(*this,_timeSinceGameUpdate);
	  }
  }

  void GraphicsEngine::addToRenderQueue(sf::Drawable& _asset, unsigned short int _zbuf)
  {
	  RenderOperation renderOperation(_asset,_zbuf); 
	  m_renderQueue.push(renderOperation);
  }

}
