#pragma once

#include "Light.h"

class WhiteLight : public Light
{
public:
	WhiteLight(std::string name, Vector2D pos);
	virtual ~WhiteLight();
};
