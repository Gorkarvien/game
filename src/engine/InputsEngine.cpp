#include "InputsEngine.h"
#include <iostream>

namespace engine
{
    InputsEngine::InputsEngine()
    {
        return;
    }

    void InputsEngine::proceedEvent(sf::Event::KeyEvent event){
        std::cout << "key !" << std::endl;
    return;
    }

	void InputsEngine::proceedEvent(sf::Event event){
        std::cout << "mouse" << std::endl;
    return;
    }

}