#pragma once

#include "Behavior.h"

class PlayerMoveBehavior : public Behavior
{
public:
	PlayerMoveBehavior(std::string name, Vector2D velocity, Rectangle* destiny, Vector2D airplaneSize);
	virtual ~PlayerMoveBehavior();

	void changeVelocity(Vector2D velocity);
	Vector2D getVelocity() const;

	void run() override;
private:
	Vector2D next_position;
	Vector2D velocity;
	Rectangle* destiny;
	Vector2D airplaneSize;
};

