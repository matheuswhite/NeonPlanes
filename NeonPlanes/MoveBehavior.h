#pragma once

#include "Behavior.h"
#include "Rectangle.h"

class MoveBehavior : public Behavior
{
public:
	MoveBehavior(std::string name, Vector2D velocity, Rectangle* destiny, bool* collided);
	virtual ~MoveBehavior();

	void changeVelocity(Vector2D velocity);
	Vector2D getVelocity() const;

	void run();
private:
	Vector2D prev_position;
	Vector2D velocity;
	Rectangle* destiny;
	bool* collided;
};
