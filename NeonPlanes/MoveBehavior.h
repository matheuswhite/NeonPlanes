#pragma once

#include "Behavior.h"

class MoveBehavior : public Behavior
{
public:
	MoveBehavior(std::string name, Vector2D velocity, Rectangle* destiny);
	virtual ~MoveBehavior();

	void changeVelocity(Vector2D velocity);
	Vector2D getVelocity() const;

	void run() override;
private:
	Vector2D velocity;
	Rectangle* destiny;
	bool collided;
};
