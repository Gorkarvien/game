#include "engine/GameEngine.h"
#include <SFML/Graphics.hpp>

int main(int argc, char **argv)
{
//ajouter gestion d'argument

	engine::GameEngine gameEngine;
	gameEngine.initialization();
	gameEngine.main_loop();

  return 0; 
}
