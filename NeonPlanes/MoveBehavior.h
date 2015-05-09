#pragma once

#include "Behavior.h"
#include "Rectangle.h"

class MoveBehavior : public Behavior
{
public:
	MoveBehavior(std::string name, Vector2D velocity, Rectangle* destiny);
	virtual ~MoveBehavior();

	void changeVelocity(Vector2D velocity);

	void run();
private:
	Vector2D velocity;
	Rectangle* destiny;
};
