#pragma once

#include "GameObject.h"

class Projectile : public GameObject
{
public:
	Projectile(std::string name);
	virtual ~Projectile();
};
