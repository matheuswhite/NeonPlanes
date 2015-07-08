#pragma once

#include "Projectile.h"

class RedProjectile : public Projectile
{
public:
	RedProjectile(std::string name, Vector2D pos);
	virtual ~RedProjectile();
};
