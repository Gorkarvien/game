#include "GameplayEngine.h"
#include "GameActor.h"
#include "Renderable.h"
#include "GraphicsEngine.h"

namespace TFG
{
	GameplayEngine::GameplayEngine(engine::GraphicsEngine* _graphEngine)
	{
		this->init();
		_graphEngine->registerRenderable(*bob);
	}

	void GameplayEngine::init(){
		bob= new GameActor();
	}

  void GameplayEngine::update(int _timeStep)
  {
	  
	bob->update(_timeStep);//move in a game word variable and update in function above?
    return;
  }

	GameActor& GameplayEngine::getActor()
	{
		return *bob;
	}
}
