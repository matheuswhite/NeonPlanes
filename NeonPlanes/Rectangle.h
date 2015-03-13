#pragma once

#include "Vector2D.h"

class Rectangle
{
public:
	Rectangle() {}
	Rectangle(Vector2D* position, Vector2D* size);
	virtual ~Rectangle();

	SDL_Rect* getRectSDL();

	Vector2D* getPosition() const;
	Vector2D* getSize() const;
	Vector2D* getCenter() const;
	Vector2D* getHalfDimension() const;

	bool contains(Vector2D* v) const;
	bool intersects(Rectangle* r) const;

	void switchPosition(Vector2D* position);
protected:
	Vector2D* position;
	Vector2D* size;
};