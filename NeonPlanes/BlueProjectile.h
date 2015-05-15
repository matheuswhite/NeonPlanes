#pragma once

#include "Projectile.h"

class BlueProjectile : public Projectile
{
public:
	BlueProjectile(std::string name, Vector2D pos);
	virtual ~BlueProjectile();
};
