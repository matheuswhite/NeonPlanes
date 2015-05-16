#pragma once

#include "Light.h"

class RedLight : public Light
{
public:
	RedLight(std::string name, Vector2D pos);
	virtual ~RedLight();
};
