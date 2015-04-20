#include "Rectangle.h"

Rectangle::Rectangle(const Vector2D& position, const Vector2D& size, double angle) : position(position), size(size), angle(angle)
{
	this->base.first = Vector2D(1, 0).rotatedVector(this->angle);
	this->base.second = Vector2D(0, 1).rotatedVector(this->angle);
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
	return (this->position + (this->size / 2.0)).rotatedVector(angle);
}

Vector2D Rectangle::getHalfDimension() const {
	return this->size / 2.0;
}

double Rectangle::getAngle() const {
	return this->angle;
}

std::pair<Vector2D, Vector2D> Rectangle::getBase() const {
	return this->base;
}

Vector2D Rectangle::getTopLeft() {
	return this->position;
}

Vector2D Rectangle::getTopRight() {
	return Vector2D(this->position.x + this->size.x, this->position.y).rotatedVector(this->angle);
}

Vector2D Rectangle::getBottomLeft() {
	return Vector2D(this->position.x, this->position.y + this->size.y).rotatedVector(this->angle);
}

Vector2D Rectangle::getBottomRight() {
	return Vector2D(this->position + this->size).rotatedVector(this->angle);
}

bool Rectangle::contains(const Vector2D& v) const {
	Vector2D distance = this->getCenter() - v;
	Vector2D halfDimension = this->getPosition() + this->getHalfDimension().rotatedVector(this->angle);

	return (distance.projectionLenght(this->base.first) <= halfDimension.projectionLenght(this->base.first)) &&
		(distance.projectionLenght(this->base.second) <= halfDimension.projectionLenght(this->base.second));
}

bool Rectangle::intersects(Rectangle* r) {
	bool order[2];
	/*
		0:3   - first rect proj in uBaseFirst 
		4:7   - second rect proj in uBaseFirst 
	*/
	double uProjections[2][4] = { { (this->getTopLeft().projectionLenght(this->base.first)), (this->getTopRight().projectionLenght(this->base.first)), (this->getBottomLeft().projectionLenght(this->base.first)), (this->getBottomRight().projectionLenght(this->base.first)) },
								  { (r->getTopLeft().projectionLenght(this->base.first)), (r->getTopRight().projectionLenght(this->base.first)), (r->getBottomLeft().projectionLenght(this->base.first)), (r->getBottomRight().projectionLenght(this->base.first)) } };
	
	/*
	0:3   - first rect proj in vBaseFirst 
	4:7   - second rect proj in vBaseFirst 
	*/
	double vProjections[2][4] = { { (this->getTopLeft().projectionLenght(this->base.second)), (this->getTopRight().projectionLenght(this->base.second)), (this->getBottomLeft().projectionLenght(this->base.second)), (this->getBottomRight().projectionLenght(this->base.second)) },
								  { (r->getTopLeft().projectionLenght(this->base.second)), (r->getTopRight().projectionLenght(this->base.second)), (r->getBottomLeft().projectionLenght(this->base.second)), (r->getBottomRight().projectionLenght(this->base.second)) } };

	double lowest[4] = { uProjections[0][utility::checkLowest(uProjections[0], 4)], uProjections[1][utility::checkLowest(uProjections[1], 4)], vProjections[0][utility::checkLowest(vProjections[0], 4)], vProjections[1][utility::checkLowest(vProjections[1], 4)] };
	double largest[4] = { uProjections[0][utility::checkLargest(uProjections[0], 4)], uProjections[1][utility::checkLargest(uProjections[1], 4)], vProjections[0][utility::checkLargest(vProjections[0], 4)], vProjections[1][utility::checkLargest(vProjections[1], 4)] };

	//U
	order[0] = lowest[0] <= lowest[1];
	//V
	order[1] = lowest[2] <= lowest[3];


	if (order[0] && order[1]) {
		if ((largest[0] -  lowest[1]) > 0) return false;
		if ((largest[2] - lowest[3]) > 0) return false;
	}
	else if (!order[0] && order[1]) {
		if ((largest[1] - lowest[0]) > 0) return false;
		if ((largest[2] - lowest[3]) > 0) return false;
	}
	else if (order[0] && !order[1]) {
		if ((largest[0] - lowest[1]) > 0) return false;
		if ((largest[3] - lowest[2]) > 0) return false;
	}
	else {
		if ((largest[1] - lowest[0]) > 0) return false;
		if ((largest[3] - lowest[2]) > 0) return false;
	}

	return true;
}

void Rectangle::changePosition(const Vector2D& position) {
	this->position = position;
}
