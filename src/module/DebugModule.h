#ifndef DEBUG_MODULE_H
#define DEBUG_MODULE_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
namespace engine
{
	class GraphicsEngine;
}

namespace module
{
  class DebugModule
  {
  protected:
      engine::GraphicsEngine& m_graphicsEngine;

        sf::Text m_fpsDisplay;
		sf::Font m_font;
      float m_averageFps;
      float m_fpsTab[30];
      int m_fpsTabIndex;
      static const int m_nbFpsSample=30;
  public:
    DebugModule(engine::GraphicsEngine*);
    ~DebugModule();
    int update(sf::Time);
  };
}
#endif
