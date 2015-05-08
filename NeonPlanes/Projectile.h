#pragma once

#include "GameObject.h"
#include "StaticSprite.h"

class Projectile : public GameObject
{
public:
	Projectile(std::string name);
	virtual ~Projectile();
};
