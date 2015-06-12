#include "ShootBehavior.h"

ShootBehavior::ShootBehavior(std::string name, std::function<void(void)> shootFunction) : shootFunction(shootFunction), Behavior(name)
{
}

ShootBehavior::~ShootBehavior()
{
}

void ShootBehavior::run() {
	this->shootFunction();
}