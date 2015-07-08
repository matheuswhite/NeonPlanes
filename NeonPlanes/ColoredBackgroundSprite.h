#pragma once

#include "Sprite.h"

class ColoredBackgroundSprite : public Sprite
{
public:
	ColoredBackgroundSprite(Rectangle* destiny, std::string name, SDL_Color color);
	virtual ~ColoredBackgroundSprite();

	void draw() override;
	void setColor(SDL_Color color);
	SDL_Color getColor() const;
private:
	SDL_Color color;
};
