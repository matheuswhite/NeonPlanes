#include "BlueProjectile.h"

BlueProjectile::BlueProjectile(std::string name, Vector2D pos) : Projectile(name, pos)
{
	this->addComponent(new Rectangle(this->pos, Vector2D(54, 37), "destiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("destiny"), "BlueProjectile.png", "StaticSprite"));
}

BlueProjectile::~BlueProjectile()
{
}
