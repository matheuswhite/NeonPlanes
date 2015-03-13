#include "Rectangle.h"

Rectangle::Rectangle(Vector2D* position, Vector2D* size)
{
	this->position = position;
	this->size = size;
}

Rectangle::~Rectangle()
{
	this->position = nullptr;
	this->size = nullptr;
}

SDL_Rect* Rectangle::getRectSDL() {
	SDL_Rect* temp = new SDL_Rect();

	temp->x = this->position->x;
	temp->y = this->position->y;
	temp->w = this->size->x;
	temp->h = this->size->y;

	return temp;
}

Vector2D* Rectangle::getCenter() const { 
	return &(*this->position + (*this->size) / 2);
}

Vector2D* Rectangle::getHalfDimension() const {
	return &(*this->size/2);
}

bool Rectangle::contains(Vector2D* v) const {
	Vector2D distance = *this->getCenter() - *v;

	return (abs(distance.x) <= this->getHalfDimension()->x) && (abs(distance.y) <= this->getHalfDimension()->y);
}

bool Rectangle::intersects(Rectangle* r) const {
	Vector2D distance(abs(this->getCenter()->x - r->getCenter()->x), abs(this->getCenter()->y - r->getCenter()->y));
	Vector2D distance2 = *this->getHalfDimension() + *r->getHalfDimension();
	Vector2D distance3 = distance - distance2;

	return (distance3.x < 0) && (distance3.y < 0);
}

void Rectangle::switchPosition(Vector2D* position) {
	this->position = position;
}