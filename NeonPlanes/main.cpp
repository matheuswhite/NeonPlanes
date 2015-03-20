#include "Game.h"

int main(int argc, char **argv) {
	bool running = true;
	float startTime = 0;
	float elapsedTime = 0;
	int frames = 0;
	float totalTime = 0;
	
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
#if _DEBUG
		if (totalTime >= 1000) {
			FPS_HUD::updateFPS(frames);
			totalTime = 0;
			frames = 0;
		}
#endif
		startTime = SDL_GetTicks();

		running = game->handlingEvents();

		if (!running)
			break;

		game->update();
		game->draw();

		elapsedTime = startTime - SDL_GetTicks();

		if (elapsedTime < GAME_FPS) {
			SDL_Delay(GAME_FPS - elapsedTime);
#if _DEBUG
			totalTime += GAME_FPS;
		}
		else { 
			totalTime += elapsedTime;
		}
#else
		}
#endif
		frames++;
	}

	delete game;

	return 0;
}
