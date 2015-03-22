#include "Game.h"

int main(int argc, char **argv) {
	bool running = true;
	Uint32 startTime = 0;
	Uint32 elapsedTime = 0;
	int frames = 0;
	Uint32 totalTime = 0;
	
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
		if (totalTime >= 1000) {
			system("cls");
			auto hud = (FPS_HUD*)game->getGameWorld()->getCurrentState()->getLayer("Debug")->getGameObject("class FPS_HUD");
			hud->updateFPS(frames);
			std::cerr << "Time: " << totalTime << "\nStartTime: " << startTime << "\nElapsedTime: " << elapsedTime << "\nFrames: " << frames << std::endl;
			totalTime = 0;
			frames = 0;
		}
		running = game->handlingEvents();

		if (!running)
			break;

		game->update();
		game->draw();

		elapsedTime = SDL_GetTicks();
		if (elapsedTime - startTime < GAME_FPS) {
			SDL_Delay(GAME_FPS - (elapsedTime - startTime));
			totalTime += GAME_FPS;
			startTime = GAME_FPS + startTime;
		}
		else { 
			totalTime += elapsedTime - startTime;
			startTime = elapsedTime;
		}
		frames++;

		//std::cerr << "Time: " << totalTime << "\nStartTime: " << startTime << "\nElapsedTime: " << elapsedTime << "\nFrames: " << frames << std::endl << std::endl;
	}

	delete game;

	return 0;
}
