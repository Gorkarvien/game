#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <SFML/System.hpp>
#include "PhysicEngine.h"

namespace sf
{
	class RenderWindow;
}

namespace module
{
	class DebugModule;
}

namespace TFG
{
	class GameplayEngine;
}

namespace engine
{
	class InputsEngine;
	class GraphicsEngine;

	class GameEngine
	{
		public:
			static const int MAXFPS = 120;
			static const int MS_PER_UPDATE=20;
			static const int MAX_FRAME_SKIP=100;

		public:
			int initialization();
			int main_loop();
			void processInput(sf::RenderWindow * window,InputsEngine* inputsEngine);

		private:
			TFG::GameplayEngine* m_gameplayEngine; 
			InputsEngine* m_inputsEngine;
			GraphicsEngine* m_graphicsEngine;
			sf::RenderWindow* m_window;
			PhysicEngine* m_physicsEngine;


			sf::Clock m_clock;


			//to clean
			module::DebugModule* debug;
	};
}

#endif
