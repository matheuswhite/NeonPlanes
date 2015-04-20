#pragma once

#include "Vector2D.h"
#include "Component.h"

class Rectangle : public Component
{
public:
	Rectangle(const Vector2D& position, const Vector2D& size, double angle);
	virtual ~Rectangle();

	SDL_Rect* getRectSDL();

	Vector2D getPosition() const;
	Vector2D getSize() const;
	Vector2D getCenter() const;
	Vector2D getHalfDimension() const;

	double getAngle() const;
	std::pair<Vector2D, Vector2D> getBase() const;

	Vector2D getTopLeft();
	Vector2D getTopRight();
	Vector2D getBottomLeft();
	Vector2D getBottomRight();

	bool contains(const Vector2D& v) const;
	bool intersects(Rectangle* r);

	void changePosition(const Vector2D& position);

private:
	Vector2D position;
	Vector2D size;

	double angle;
	std::pair<Vector2D, Vector2D> base;
};
