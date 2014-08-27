#include "GameplayEngine.h"
#include "GameActor.h"

namespace TFG
{
	GameplayEngine::GameplayEngine()
	{
		this->init();
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
