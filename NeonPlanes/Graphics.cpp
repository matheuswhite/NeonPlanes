#include "Graphics.h"

Graphics::Graphics() {
	IMG_Init(IMG_INIT_PNG);
}

Graphics::~Graphics() {
	IMG_Quit();
}

void Graphics::sinAnimation(double limit, Texture* texture) {
	double current = 0;
	const double pass = 0.1;

	texture->loadFromFile(Game::getRenderer());
	texture->getTexture();

	while (current < limit) {
		if (current > limit/2 - 0.1 && current < limit/2 + 0.2) {
			// std::cout << "delay!" << std::endl; 3 delays
			SDL_Delay(750);
		}
		SDL_RenderClear(Game::getRenderer());
		texture->setBlendMode(SDL_BLENDMODE_BLEND);
		texture->setAlphaModulation(sin(current) * 255);
		texture->render(nullptr,nullptr,Game::getRenderer());
		SDL_RenderPresent(Game::getRenderer());

		current += pass;
		SDL_Delay(100);
	}

	delete texture;
	SDL_RenderClear(Game::getRenderer());
	SDL_RenderPresent(Game::getRenderer());
}