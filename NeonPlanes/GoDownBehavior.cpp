#include "GoDownBehavior.h"

GoDownBehavior::GoDownBehavior(std::string name, float velocityGoDown_y, Rectangle* destiny, float airplaneSize_y) : velocityGoDown_y(velocityGoDown_y), destiny(destiny), airplaneSize_y(airplaneSize_y), Behavior(name)
{
}

GoDownBehavior::~GoDownBehavior()
{
}

void GoDownBehavior::run() {
	auto pos = this->destiny->getPosition().y;
	if (pos >= (BOTTOM_BOUND - (airplaneSize_y * 2) - 10)) {
		this->active = false;
	}
	else {
		this->destiny->changePosition(Vector2D(this->destiny->getPosition().x, this->destiny->getPosition().y - abs(this->velocityGoDown_y)));
	}
}