#include "InputsEngine.h"
#include <iostream>
#include "Command.h"

namespace engine
{
	InputsEngine::InputsEngine(TFG::GameActor& _bob):
	bob(_bob)
    {
		m_commandList[0]=new TFG::VoidCommand();
		m_commandList[1]=new TFG::MoveDownCommand();
		m_commandList[2]=new TFG::MoveUpCommand();
		m_commandList[3]=new TFG::MoveLeftCommand();
		m_commandList[4]=new TFG::MoveRightCommand();

		for(int i=0; i<sf::Keyboard::KeyCount;i++){
			m_control[i]=m_commandList[0];
		}
		m_control[sf::Keyboard::Z]=m_commandList[2];
		m_control[sf::Keyboard::S]=m_commandList[1];
		m_control[sf::Keyboard::Q]=m_commandList[3];
		m_control[sf::Keyboard::D]=m_commandList[4];


        return;
    }

    void InputsEngine::proceedEvent(sf::Event::KeyEvent event){
        // std::cout << "key !" << std::endl;
		//bad because key event don't keep release or pressed state.
		

    return;
    }

	void InputsEngine::proceedEvent(sf::Event event)
	{
		if(event.type == sf::Event::KeyPressed)
		{
			m_control[event.key.code]->execute(bob);
		}
		else if(event.type == sf::Event::KeyReleased)
		{
			m_control[event.key.code]->undo(bob);
		}
		return;
    }

}