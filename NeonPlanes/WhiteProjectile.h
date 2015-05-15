#pragma once

#include "Projectile.h"

class WhiteProjectile : public Projectile
{
public:
	WhiteProjectile(std::string name, Vector2D pos);
	virtual ~WhiteProjectile();
};
