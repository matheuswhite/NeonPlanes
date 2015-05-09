#include "BlueProjectile.h"

BlueProjectile::BlueProjectile(std::string name) : Projectile(name)
{
	this->addComponent(new Rectangle(Vector2D(280, 150), Vector2D(54, 37), "destiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("destiny"), "BlueProjectile.png", "StaticSprite"));
}

BlueProjectile::~BlueProjectile()
{
}
