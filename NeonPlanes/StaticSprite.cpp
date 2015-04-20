#include "StaticSprite.h"

StaticSprite::StaticSprite(Rectangle* destiny, std::string pathImage, std::string name) : Sprite(destiny, pathImage, name)
{
	this->texture->loadImage(renderer, IMAGE_PATH + pathImage);
}

StaticSprite::~StaticSprite()
{
}

void StaticSprite::draw() {
	if (this->source == nullptr && this->destiny != nullptr) {
		Graphics::render(nullptr, this->destiny->getRectSDL(), this->texture->getTexture());
	}
	else if (this->source != nullptr && this->destiny == nullptr) {
		Graphics::render(this->source->getRectSDL(), nullptr, this->texture->getTexture());
	}
	else if (this->source == nullptr && this->destiny == nullptr) {
		Graphics::render(nullptr, nullptr, this->texture->getTexture());
	}
	else {
		Graphics::render(this->source->getRectSDL(), this->destiny->getRectSDL(), this->texture->getTexture());
	}
}
