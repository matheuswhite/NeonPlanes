#pragma once

#include "Light.h"

class YellowLight : public Light
{
public:
	YellowLight(std::string name, Vector2D pos);
	virtual ~YellowLight();
};
