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
	void updateValue(std::string value);
private:
	Font* font;
};

