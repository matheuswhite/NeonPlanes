#pragma once

#include "Sprite.h"

class DynamicTextSprite : public Sprite
{
public:
	DynamicTextSprite(Rectangle* destiny, Font* font, std::string name);
	virtual ~DynamicTextSprite();

	void draw();

	Font* getFont() const;
	void updateValue(std::string value);
private:
	Font* font;
};
