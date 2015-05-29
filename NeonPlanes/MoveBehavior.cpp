#include "MoveBehavior.h"

MoveBehavior::MoveBehavior(std::string name, Vector2D velocity, Rectangle* destiny, bool* collided) : velocity(velocity), destiny(destiny), collided(collided), Behavior(name)
{
}

MoveBehavior::~MoveBehavior()
{
}

void MoveBehavior::changeVelocity(Vector2D velocity) {
	this->velocity = velocity;
}

void MoveBehavior::run() {
	if (this->collided != nullptr) {
		if (!(*this->collided)) {
			this->destiny->changePosition(this->destiny->getPosition() + velocity);
		}
		else {
			*this->collided = false;
		}
	}
	else {
		this->destiny->changePosition(this->destiny->getPosition() + velocity);
	}
}

Vector2D MoveBehavior::getVelocity() const {
	return this->velocity;
}