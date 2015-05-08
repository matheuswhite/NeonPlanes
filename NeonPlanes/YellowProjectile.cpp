#include "YellowProjectile.h"

YellowProjectile::YellowProjectile(std::string name) : Projectile(name)
{
	this->addComponent(new Rectangle(Vector2D(100, 150), Vector2D(54, 37), "rectDestiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("rectDestiny"), "YellowProjectile.png", "yellow"));
}

YellowProjectile::~YellowProjectile()
{
}
