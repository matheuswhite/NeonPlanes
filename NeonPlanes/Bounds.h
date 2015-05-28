#pragma once

#include "GameObject.h"

class Bounds : public GameObject
{
public:
	Bounds(std::string name, Rectangle* destiny);
	virtual ~Bounds();
};
