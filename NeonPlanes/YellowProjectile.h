#pragma once

#include "Projectile.h"

class YellowProjectile : public Projectile
{
public:
	YellowProjectile(std::string name, Vector2D pos);
	virtual ~YellowProjectile();
};
