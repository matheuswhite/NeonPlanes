#include "Graphics.h"

Graphics::Graphics() {
}

Graphics::~Graphics() {
}

void Graphics::sinAnimation(double limit, SDL_Texture* texture) {
	double current = 0;
	const double pass = 0.1;

	while (current < limit) {
		if (current > limit/2 - 0.1 && current < limit/2 + 0.2) {
			SDL_Delay(750);
		}

		SDL_RenderClear(renderer);

		setBlendMode(SDL_BLENDMODE_BLEND, texture);
		setAlphaModulation(sin(current) * 255, texture);
		render(nullptr,nullptr,texture);

		SDL_RenderPresent(renderer);

		current += pass;
		SDL_Delay(100);
	}
}

void Graphics::render(SDL_Rect* source, SDL_Rect* destiny, SDL_Texture* texture) {
	SDL_RenderCopy(renderer, texture, source, destiny);
}

void Graphics::setAlphaModulation(Uint8 alpha, SDL_Texture* texture) {
	SDL_GetTextureAlphaMod(texture, &alpha);
}

void Graphics::setBlendMode(SDL_BlendMode mode, SDL_Texture* texture) {
	SDL_SetTextureBlendMode(texture, mode);
}

void Graphics::createColorRect(SDL_Rect* destiny, SDL_Color color) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, destiny);
}