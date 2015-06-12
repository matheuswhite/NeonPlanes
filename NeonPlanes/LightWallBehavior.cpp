#include "LightWallBehavior.h"

LightWallBehavior::LightWallBehavior(std::string name, std::function<void(void)> lightWallFunction) : lightWallFunction(lightWallFunction), Behavior(name)
{
}

LightWallBehavior::~LightWallBehavior()
{
}

void LightWallBehavior::run() {
	this->lightWallFunction();
}