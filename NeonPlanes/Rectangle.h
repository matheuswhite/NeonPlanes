#pragma once

#include "Vector2D.h"
#include "Component.h"

class Rectangle : public Component
{
public:
	Rectangle(const Vector2D& position, const Vector2D& size, std::string name);
	virtual ~Rectangle();

	SDL_Rect* getRectSDL();

	Vector2D getPosition() const;
	Vector2D getSize() const;
	Vector2D getCenter() const;
	Vector2D getHalfDimension() const;

	bool contains(const Vector2D& v) const;
	bool intersects(Rectangle* r);

	void changePosition(const Vector2D& position);

private:
	Vector2D position;
	Vector2D size;
};
