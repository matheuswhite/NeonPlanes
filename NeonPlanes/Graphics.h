#pragma once

#include "core.h"

class Graphics
{
public:
	Graphics();
	virtual ~Graphics();
	static void sinAnimation(double limit, SDL_Texture* texture);
	static void render(SDL_Rect* source, SDL_Rect* destiny, SDL_Texture* texture);
	static void renderRotated(SDL_Rect* source, SDL_Rect* destiny, SDL_Texture* texture, double angle);

private:
	static void setAlphaModulation(Uint8 alpha, SDL_Texture* texture);
	static void setBlendMode(SDL_BlendMode mode, SDL_Texture* texture);
};
