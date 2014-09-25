#ifndef RENDER_OPERATION_H
#define RENDER_OPERATION_H

//#include <SFML/Graphics.hpp>

namespace sf{
	class Drawable;
}

namespace engine
{
  struct RenderOperation
  {
	  RenderOperation(sf::Drawable& _asset, unsigned short int _z=0);
	  sf::Drawable* m_drawable;
	  unsigned short int m_z;

	  struct comp{ 
		  bool operator()(RenderOperation a,RenderOperation b){return a.m_z<b.m_z;}
	  };
  };
}

#endif
