#include "DashBehavior.h"

DashBehavior::DashBehavior(std::string name, float velocityDash_y, Rectangle* destiny, float airplaneSize_y) : velocityDash_y(velocityDash_y), destiny(destiny), airplaneSize_y(airplaneSize_y), Behavior(name)
{
}

DashBehavior::~DashBehavior()
{
}

void DashBehavior::run() {
	auto pos = this->destiny->getPosition().y;
	if (pos <= TOP_ZONE) {
		this->active = false;
	}
	else {
		this->destiny->changePosition(Vector2D(this->destiny->getPosition().x, this->destiny->getPosition().y - abs(this->velocityDash_y)));
	}
}