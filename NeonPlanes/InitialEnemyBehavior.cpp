#include "InitialEnemyBehavior.h"

InitialEnemyBehavior::InitialEnemyBehavior(Behavior* initialBehavior, float velocity_x, Rectangle* destiny, float airplaneSize_x, std::string name) : flagInitialize(nullptr), initialBehavior(initialBehavior), velocity_x(velocity_x), destiny(destiny), airplaneSize_x(airplaneSize_x), Behavior(name)
{
}

InitialEnemyBehavior::~InitialEnemyBehavior()
{
}

void InitialEnemyBehavior::setFlagInitialize(bool* flag) {
	this->flagInitialize = flag;
}

void InitialEnemyBehavior::run() {
	auto pos = this->destiny->getPosition();

	if ((pos.x >= 5 && pos.x <= 8) || (pos.x >= SCREEN_WIDTH - 8 - airplaneSize_x && pos.x <= SCREEN_WIDTH - 5 - airplaneSize_x)) {
		this->active = false;
		this->initialBehavior->setActive(true);

		if (this->flagInitialize != nullptr) {
			*this->flagInitialize = true;
		}
	}
	else {
		this->destiny->changePosition(Vector2D(pos.x + velocity_x, pos.y));
	}
}