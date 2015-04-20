#include "StaticSprite.h"

StaticSprite::StaticSprite(Rectangle* destiny, std::string name) : Sprite(destiny, name)
{
	this->texture->loadImage(renderer, IMAGE_PATH + this->name);
}

StaticSprite::~StaticSprite()
{
}

void StaticSprite::draw() {
	Graphics::render(this->source->getRectSDL(), this->destiny->getRectSDL(), this->texture->getTexture());
}
