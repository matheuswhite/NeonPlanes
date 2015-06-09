#pragma once

#include "Sprite.h"

class StaticTextSprite : public Sprite
{
public:
	StaticTextSprite(Rectangle* destiny, Font* font, std::string name);
	virtual ~StaticTextSprite();

	void draw() override;

	Font* getFont() const;
private:
	Font* font;
};
