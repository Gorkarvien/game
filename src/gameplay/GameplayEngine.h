#ifndef GAMEPLAY_ENGINE_H
#define GAMEPLAY_ENGINE_H
#include <SFML/System.hpp>

namespace engine{
	class GraphicsEngine;
}

namespace TFG
{
	class GameActor;

	class GameplayEngine
	{
		public:
			GameplayEngine(engine::GraphicsEngine* _graphEngine);
			void init();
			void update(int _timeStep);
			GameActor& getActor();

		private:
			GameActor* bob;

	};
}

#endif
