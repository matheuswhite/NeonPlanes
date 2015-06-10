#include "LightWallBehavior.h"

LightWallBehavior::LightWallBehavior(std::string name, std::function<void(const GameObject&)> lightWallFunction, GameObject* enemy) : lightWallFunction(lightWallFunction), enemy(enemy), Behavior(name)
{
}

LightWallBehavior::~LightWallBehavior()
{
}

void LightWallBehavior::run() {
	this->lightWallFunction(*enemy);
}