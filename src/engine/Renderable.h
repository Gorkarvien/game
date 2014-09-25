#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <SFML/System.hpp>


namespace engine
{
	class GraphicsEngine;
  class Renderable
  {
	public :
		virtual ~Renderable(){}
		virtual void callToRender(GraphicsEngine& _graphicsEngine, sf::Time _timeSinceGameUpdate)=0;

  };
}

#endif
