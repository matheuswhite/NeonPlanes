#pragma once

#include "Sprite.h"

class TextSprite : public Sprite
{
public:
	TextSprite(Rectangle* destiny, Font* font, std::string name);
	virtual ~TextSprite();

	void draw();

	Font* getFont() const;
	void updateValue(std::string value);
private:
	Font* font;
};

