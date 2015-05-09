#include "WhiteProjectile.h"

WhiteProjectile::WhiteProjectile(std::string name) : Projectile(name)
{
	this->addComponent(new Rectangle(Vector2D(200, 250), Vector2D(54, 37), "destiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("destiny"), "WhiteProjectile.png", "StaticSprite"));
	this->addBehavior(new MoveBehavior("moveUPBehavior", Vector2D(0, -15), (Rectangle*)this->getComponent("destiny")));
}

WhiteProjectile::~WhiteProjectile()
{
}
