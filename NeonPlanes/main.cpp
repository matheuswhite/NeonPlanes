#include "Game.h"
#include "Timers.h"

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

#if _DEBUG
	SlaveTimer* testTimer = new SlaveTimer(6000);
#endif

	while (running) {
		if (totalTime >= 1000) {
			system("cls");
			auto hud = (FPS_HUD*)game->getGameWorld()->getCurrentState()->getLayer("Debug")->getGameObject("class FPS_HUD");
			hud->updateFPS(frames);
			std::cerr << "Time: " << totalTime << "\nFrames: " << frames << std::endl;
			totalTime = 0;
			frames = 0;
#if _DEBUG
			if (testTimer->isFinish()) {
				std::cerr << "Timer! " << testTimer->getDuration() << std::endl;
				testTimer = new SlaveTimer(testTimer->getDuration() + 1000);
			}
#endif
		}

		running = game->handlingEvents();

		if (!running)
			break;
		
		game->update();
		game->draw();

		elapsedTime = SDL_GetTicks();
		if (elapsedTime - startTime < GAME_FPS) {
			SDL_Delay(GAME_FPS - (elapsedTime - startTime));
			MasterTimer::updateSlaves(GAME_FPS);
			totalTime += GAME_FPS;
			startTime = GAME_FPS + startTime;
		}
		else { 
			MasterTimer::updateSlaves(elapsedTime - startTime);
			totalTime += elapsedTime - startTime;
			startTime = elapsedTime;
		}
		frames++;
	}

	delete game;

	return 0;
}
