#ifndef GAMEPLAY_ENGINE_H
#define GAMEPLAY_ENGINE_H
#include <SFML/System.hpp>

namespace TFG
{
	class GameActor;
	class PhysicsEngine;

	class GameplayEngine
	{
		public:
			GameplayEngine();
			void init();
			void update(int _timeStep);
			GameActor& getActor();

		private:
			GameActor* bob;
			PhysicsEngine* m_physicsEngine;

	};
}

#endif
