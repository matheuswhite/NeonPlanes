#include "MoveBehavior.h"

MoveBehavior::MoveBehavior(std::string name, Vector2D velocity, Rectangle* destiny) : velocity(velocity), destiny(destiny), Behavior(name)
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