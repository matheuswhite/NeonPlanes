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

//fazer
void Graphics::renderRotated(SDL_Rect* source, SDL_Rect* destiny, SDL_Texture* texture, double angle) {

}

/*
//Texture


/*
if (object->lastPosition != position) {
object->frame = 0;
}

object->row = position;


Vector2D center(object->Width/2 * object->getFrame(), object->Height/2 * object->getRow());
Vector2D half(object->Width/2, object->Height/2);
Rectangle rect(&center, &half);

object->frame++;

object->source = &rect;

this->renderGameObject(object, renderer);
*/