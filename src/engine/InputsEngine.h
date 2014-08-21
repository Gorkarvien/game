#ifndef INPUTS_ENGINE_H
#define INPUTS_ENGINE_H

#include <SFML/Window.hpp>

//todo forward declaration class sf::Event;

namespace TFG{
	class GameActor;
	class Command;
}

namespace engine
{
  class InputsEngine
  {
  protected:

  public:
    InputsEngine(TFG::GameActor& bob);
    ~InputsEngine();

    int update();

	TFG::GameActor& bob;

	TFG::Command* m_control[sf::Keyboard::KeyCount];
	TFG::Command* m_commandList[5];


    void proceedEvent(sf::Event);
	void proceedEvent(sf::Event::KeyEvent);
  };
}
#endif
