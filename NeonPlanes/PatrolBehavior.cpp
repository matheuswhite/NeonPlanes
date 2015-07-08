#include "PatrolBehavior.h"

PatrolBehavior::PatrolBehavior(std::string name, float velocity_x, Rectangle* destiny, float airplaneSize_x) : velocity_x(velocity_x), destiny(destiny), airplaneSize_x(airplaneSize_x), Behavior(name)
{
}

PatrolBehavior::~PatrolBehavior()
{
}

void PatrolBehavior::run() {
	auto pos = this->destiny->getPosition().x;
	if (pos <= 1 || pos >= (SCREEN_WIDTH - this->airplaneSize_x)) this->velocity_x = -this->velocity_x;

	this->destiny->changePosition(Vector2D(this->destiny->getPosition().x + this->velocity_x, this->destiny->getPosition().y));
}