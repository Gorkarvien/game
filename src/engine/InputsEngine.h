#ifndef INPUTS_ENGINE_H
#define INPUTS_ENGINE_H

#include <SFML/Window.hpp>

//todo forward declaration class sf::Event;

namespace engine
{
  class InputsEngine
  {
  protected:

  public:
    InputsEngine();
    ~InputsEngine();
    int update();
    void proceedEvent(sf::Event);
  };
}
#endif
