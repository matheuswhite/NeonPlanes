#pragma once

#include "Sprite.h"
#include "Graphics.h"

class TextSprite : public Sprite
{
public:
	TextSprite(Rectangle* destiny, Font* font);
	virtual ~TextSprite();

	void draw();

	Font* getFont() const;
private:
	Font* font;
};

