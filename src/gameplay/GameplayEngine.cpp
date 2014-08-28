#include "GameplayEngine.h"
#include "GameActor.h"
#include "PhysicsEngine.h"

namespace TFG
{
	GameplayEngine::GameplayEngine()
	{
		this->init();
	}

	void GameplayEngine::init(){
		bob= new GameActor();
		m_physicsEngine = new PhysicsEngine();
	}

  void GameplayEngine::update(int _timeStep)
  {
	  
	bob->update(_timeStep);//move in a game word variable and update in function above?
	m_physicsEngine->simulateWorld();
    return;
  }

	GameActor& GameplayEngine::getActor()
	{
		return *bob;
	}
}
