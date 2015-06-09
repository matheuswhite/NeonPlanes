#include "PatrolBehavior.h"

PatrolBehavior::PatrolBehavior(std::string name, float velocity, Rectangle* destiny, float airplaneSize) : velocity(velocity), destiny(destiny), airplaneSize(airplaneSize), Behavior(name)
{
}

PatrolBehavior::~PatrolBehavior()
{
}

void PatrolBehavior::run() {
	auto pos = this->destiny->getPosition().x;
	if (pos <= 1 || pos >= (SCREEN_WIDTH - this->airplaneSize)) this->velocity = -this->velocity;

	this->destiny->changePosition(Vector2D(this->destiny->getPosition().x + this->velocity, this->destiny->getPosition().y));
}