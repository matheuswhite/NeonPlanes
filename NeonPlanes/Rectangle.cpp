#include "Rectangle.h"

Rectangle::Rectangle(const Vector2D& position, const Vector2D& size, std::string name) : position(position), size(size), Component(name)
{
}

Rectangle::~Rectangle()
{
}

SDL_Rect* Rectangle::getRectSDL() {
	SDL_Rect* temp = new SDL_Rect();

	temp->x = this->position.x;
	temp->y = this->position.y;
	temp->w = this->size.x;
	temp->h = this->size.y;

	return temp;
}

Vector2D Rectangle::getPosition() const {
	return this->position;
}

Vector2D Rectangle::getSize() const {
	return this->size;
}

Vector2D Rectangle::getCenter() const { 
	return this->position + (this->size / 2.0);
}

Vector2D Rectangle::getHalfDimension() const {
	return this->size / 2.0;
}

bool Rectangle::contains(const Vector2D& v) const {
	Vector2D sizePosition = this->size + this->position;

	return (v.x <= sizePosition.x) && (v.x >= this->position.x) && (v.y <= sizePosition.y) && (v.y >= this->position.y);
}

bool Rectangle::intersects(Rectangle* r) {
	if (abs(this->getCenter().x - r->getCenter().x) > abs(this->getHalfDimension().x + r->getHalfDimension().x)) return false;
	if (abs(this->getCenter().y - r->getCenter().y) > abs(this->getHalfDimension().y + r->getHalfDimension().y)) return false;

	return true;
}

void Rectangle::changePosition(const Vector2D& position) {
	this->position = position;
}
