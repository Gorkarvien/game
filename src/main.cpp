#include "engine/GameEngine.h"
#include <SFML/Graphics.hpp>
//#include <Windows.h>

int main(int argc, char **argv)
{
//ajouter gestion d'argument

// be sure to #include <Windows.h> .. at least temporarily
  /*  char path[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH,path);
    MessageBoxA(NULL,path,"Current Directory",MB_OK);
	*/

	engine::GameEngine gameEngine;
	gameEngine.initialization();
	gameEngine.main_loop();

  return 0; 
}
