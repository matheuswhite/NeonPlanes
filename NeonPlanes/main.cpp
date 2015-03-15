#include "Game.h"

int main(int argc, char **argv) {
	bool running = true;
	Uint32 startTime = 0;
	Uint32 elapsedTime = 0;

	
	Game* game = new Game("LAST LEVEL - V1.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOW_SHOWN);

	if (game == nullptr || !game->isInitialize()) {
		std::cerr << "Error in main. Line: " << __LINE__ << std::endl;
#if _DEBUG
		getchar();
#endif
		return 1;
	}

	if (!game->initialize()) {
#if _DEBUG
		getchar();
#endif
		return 2;
	}


	while (running) {
		startTime = SDL_GetTicks();

		running = game->handlingEvents();
			
		if (!running)
			break;

		//game->update();
		//game->draw();
			
		elapsedTime = startTime - SDL_GetTicks();
		if (elapsedTime < GAME_FPS) {
			SDL_Delay(GAME_FPS - elapsedTime);
		}
	}

	delete game;

	return 0;
}
