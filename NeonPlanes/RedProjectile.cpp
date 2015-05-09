#include "RedProjectile.h"

RedProjectile::RedProjectile(std::string name) : Projectile(name)
{
	this->addComponent(new Rectangle(Vector2D(195, 150), Vector2D(54, 37), "destiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("destiny"), "RedProjectile.png", "StaticSprite"));
}

RedProjectile::~RedProjectile()
{
}
