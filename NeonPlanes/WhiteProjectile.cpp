#include "WhiteProjectile.h"

WhiteProjectile::WhiteProjectile(std::string name, Vector2D pos) : Projectile(name, pos)
{
	this->addComponent(new Rectangle(this->pos, Vector2D(54, 37), "destiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("destiny"), "WhiteProjectile.png", "StaticSprite"));
	this->addBehavior(new MoveBehavior("moveUPBehavior", Vector2D(0, -8), (Rectangle*)this->getComponent("destiny"), nullptr));
}

WhiteProjectile::~WhiteProjectile()
{
}
