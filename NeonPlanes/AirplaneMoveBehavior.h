#pragma once

#include "Behavior.h"
#include "Rectangle.h"

class AirplaneMoveBehavior : public Behavior
{
public:
	AirplaneMoveBehavior(std::string name, Vector2D velocity, Rectangle* destiny, Vector2D airplaneSize);
	virtual ~AirplaneMoveBehavior();

	void changeVelocity(Vector2D velocity);
	Vector2D getVelocity() const;

	void run();
private:
	Vector2D next_position;
	Vector2D velocity;
	Rectangle* destiny;
	bool collided;
	Vector2D airplaneSize;
};

