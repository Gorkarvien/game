#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

namespace engine
{
    const int MAXFPS = 120;
	const int MS_PER_UPDATE=20;
	const int MAX_FRAME_SKIP=100;

  int initialization();
  int main_loop();
}

#endif
