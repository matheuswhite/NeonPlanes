#include "VerticalScrollingSprite.h"

VerticalScrollingSprite::VerticalScrollingSprite(Rectangle* destiny, std::string name, float velocity) : Sprite(destiny, name)
{
	this->texture->loadImage(renderer, IMAGE_PATH + this->name);
	this->velocity = Vector2D(0,velocity);
}

VerticalScrollingSprite::~VerticalScrollingSprite()
{
}

void VerticalScrollingSprite::draw() {
	auto pos = this->source->getPosition() + this->velocity;
	this->source->changePosition(pos);
	Graphics::render(this->source->getRectSDL(), this->destiny->getRectSDL(), this->texture->getTexture());
}

Vector2D VerticalScrollingSprite::getVelocity() const {
	return this->velocity;
}

void VerticalScrollingSprite::changeVelocity(float velocity) {
	this->velocity.y = velocity;
}
