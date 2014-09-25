#ifndef RENDABLE_H
#define RENDABLE_H

#include <SFML/System.hpp>


namespace engine
{
  class Rendable
  {
	public :
		Rendable();
		~Rendable();
		virtual void CallToRender(sf::Time _timeSinceGameUpdate)=0;

  };
}

#endif
