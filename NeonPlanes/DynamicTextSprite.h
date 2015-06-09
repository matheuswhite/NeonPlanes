#pragma once

#include "Sprite.h"

class DynamicTextSprite : public Sprite
{
public:
	DynamicTextSprite(Rectangle* destiny, Font* font, std::string name);
	virtual ~DynamicTextSprite();

	void draw() override;

	Font* getFont() const;
	void updateValue(std::string value);
protected:
	Font* font;
};
