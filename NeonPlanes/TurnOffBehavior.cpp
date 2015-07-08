#include "TurnOffBehavior.h"

TurnOffBehavior::TurnOffBehavior(Rectangle* destiny, float airplaneSize_y, bool* gameObject_Active, std::string name) : airplaneSize_y(airplaneSize_y), destiny(destiny), gameObject_Active(gameObject_Active), Behavior(name)
{
}

TurnOffBehavior::~TurnOffBehavior()
{
}

void TurnOffBehavior::run() {
	auto pos = this->destiny->getPosition();
	if (pos.y + airplaneSize_y < TOP_BOUND || pos.y > BOTTOM_BOUND) {
		*this->gameObject_Active = false;
	}
}