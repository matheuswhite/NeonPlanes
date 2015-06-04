#include "MoveBehavior.h"

MoveBehavior::MoveBehavior(std::string name, Vector2D velocity, Rectangle* destiny) : collided(false), velocity(velocity), destiny(destiny), Behavior(name)
{
}

MoveBehavior::~MoveBehavior()
{
}

void MoveBehavior::changeVelocity(Vector2D velocity) {
	this->velocity = velocity;
}

void MoveBehavior::run() {
	this->destiny->changePosition(this->destiny->getPosition() + velocity);
}

Vector2D MoveBehavior::getVelocity() const {
	return this->velocity;
}