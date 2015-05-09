#include "WhiteProjectile.h"

WhiteProjectile::WhiteProjectile(std::string name) : Projectile(name)
{
	this->addComponent(new Rectangle(Vector2D(200, 250), Vector2D(54, 37), "rectDestiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("rectDestiny"), "WhiteProjectile.png", "white"));
	this->addBehavior(new MoveBehavior("moveUP", Vector2D(0, -15), (Rectangle*)this->getComponent("rectDestiny")));
}

WhiteProjectile::~WhiteProjectile()
{
}
