#include "GraphicsEngine.h"
#include "GameActor.h"
#include "Renderable.h"

namespace engine
{
   GraphicsEngine* GraphicsEngine::CreateGraphicsEngine(){
        //if(pomme_graphEngine==NULL){
            return new GraphicsEngine();
        //}else{
          //  return pomme_graphEngine;
        //}
    }

  GraphicsEngine::GraphicsEngine()
  {
    window = new sf::RenderWindow(sf::VideoMode(800,600), "the game port : XXXX");
    //pomme_graphEngine = this;
  }

  int GraphicsEngine::update(const TFG::GameActor& bob)
  {
    window->clear();
    // tmp
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    // end tmp
    window->draw(shape);
    window->draw(bob);
    //window->display();
    return 0;
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
