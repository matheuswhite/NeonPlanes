#include "VerticalScrollingSprite.h"

VerticalScrollingSprite::VerticalScrollingSprite(Rectangle* source, Rectangle* destiny, std::string pathImage, std::string name, float velocity) : Sprite(destiny, pathImage, name)
{
	this->texture->loadImage(renderer, IMAGE_PATH + pathImage);
	this->velocity = Vector2D(0,velocity);
	this->source = source;
	this->init_pos = source->getPosition().y;
}

VerticalScrollingSprite::~VerticalScrollingSprite()
{
}

void VerticalScrollingSprite::draw() {
	
	auto pos = this->source->getPosition() + this->velocity;

	if (pos.y <= 0) {
		pos.y = this->init_pos;
	}
	this->source->changePosition(pos);

	if (this->destiny == nullptr) {
		Graphics::render(this->source->getRectSDL(), nullptr, this->texture->getTexture());
	}
	else {
		Graphics::render(this->source->getRectSDL(), this->destiny->getRectSDL(), this->texture->getTexture());
	}
}

Vector2D VerticalScrollingSprite::getVelocity() const {
	return this->velocity;
}

void VerticalScrollingSprite::changeVelocity(float velocity) {
	this->velocity.y = velocity;
}
