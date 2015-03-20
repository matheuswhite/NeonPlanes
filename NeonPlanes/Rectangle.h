#pragma once

#include "Vector2D.h"
#include "Component.h"

class Rectangle : public Component
{
public:
	Rectangle(Vector2D* position, Vector2D* size);
	virtual ~Rectangle();

	SDL_Rect* getRectSDL();

	Vector2D* getPosition() const;
	Vector2D* getSize() const;
	Vector2D* getCenter() const;
	Vector2D* getHalfDimension() const;

	bool contains(Vector2D* v) const;
	bool intersects(Rectangle* r) const;

	void changePosition(Vector2D* position);
	void changeSize(Vector2D* size);
protected:
	Vector2D* position;
	Vector2D* size;
};
