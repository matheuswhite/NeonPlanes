#pragma once

#include "Light.h"

class BlueLight : public Light
{
public:
	BlueLight(std::string name, Vector2D pos);
	virtual ~BlueLight();
};
