#pragma once

#include "Sprite.h"

class TextSprite : public Sprite
{
public:
	TextSprite(Rectangle* destiny, std::string value, std::string font, Uint8 size, const SDL_Color& color);
	virtual ~TextSprite();

	void draw();
};

