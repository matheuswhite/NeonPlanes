#pragma once

#include "Vector2D.h"
#include "Component.h"

class Rectangle : public Component
{
public:
	Rectangle(GameObject* obj) : Component(obj) {}
	Rectangle(Vector2D* position, Vector2D* size, GameObject* obj);
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
