#include "Projectile.h"

Projectile::Projectile(std::string name, Vector2D pos) : GameObject(name)
{
	this->pos = pos + Vector2D(3, -30);
}

Projectile::~Projectile()
{
}
