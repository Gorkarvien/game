#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

namespace sf
{
	class RenderWindow;
}

namespace engine
{
	class InputsEngine;

	class GameEngine
	{
		public:
			static const int MAXFPS = 120;
			static const int MS_PER_UPDATE=20;
			static const int MAX_FRAME_SKIP=100;

		public:
			int initialization();
			int main_loop();
			void processInput(sf::RenderWindow * window,InputsEngine* inputsEngine);
	};
}

#endif
