#include "BlueProjectile.h"

BlueProjectile::BlueProjectile(std::string name) : Projectile(name)
{
	this->addComponent(new Rectangle(Vector2D(280, 150), Vector2D(54, 37), "rectDestiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("rectDestiny"), "BlueProjectile.png", "blue"));
}

BlueProjectile::~BlueProjectile()
{
}
