#include "ShootBehavior.h"

ShootBehavior::ShootBehavior(std::string name, std::function<void(const GameObject&)> shootFunction, GameObject* enemy) : shootFunction(shootFunction), enemy(enemy), Behavior(name)
{
}

ShootBehavior::~ShootBehavior()
{
}

void ShootBehavior::run() {
	this->shootFunction(*enemy);
}