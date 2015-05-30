#include "MoveBehavior.h"

MoveBehavior::MoveBehavior(std::string name, Vector2D velocity, Rectangle* destiny, bool* collided) : velocity(velocity), destiny(destiny), collided(collided), Behavior(name)
{
	this->prev_position = this->destiny->getPosition();
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
			this->prev_position = this->destiny->getPosition();
			this->destiny->changePosition(this->destiny->getPosition() + velocity);
		}
		else {
			*this->collided = false;
			this->destiny->changePosition(this->prev_position);
		}
	}
	else {
		this->destiny->changePosition(this->destiny->getPosition() + velocity);
	}
}

Vector2D MoveBehavior::getVelocity() const {
	return this->velocity;
}