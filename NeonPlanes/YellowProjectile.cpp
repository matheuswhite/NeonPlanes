#include "YellowProjectile.h"

YellowProjectile::YellowProjectile(std::string name, Vector2D pos) : Projectile(name, pos)
{
	this->addComponent(new Rectangle(this->pos, Vector2D(54, 37), "destiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("destiny"), "YellowProjectile.png", "StaticSprite"));
}

YellowProjectile::~YellowProjectile()
{
}
