#include "ColoredBackgroundSprite.h"

ColoredBackgroundSprite::ColoredBackgroundSprite(Rectangle* destiny, std::string name, SDL_Color color) : color(color), Sprite(destiny, "", name)
{
}

ColoredBackgroundSprite::~ColoredBackgroundSprite()
{
}

void ColoredBackgroundSprite::draw() {
	Graphics::createColorRect(this->destiny->getRectSDL(), this->color);
}

void ColoredBackgroundSprite::setColor(SDL_Color color) {
	this->color = color;
}

SDL_Color ColoredBackgroundSprite::getColor() const {
	return this->color;
}
