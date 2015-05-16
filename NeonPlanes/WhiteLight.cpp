#include "WhiteLight.h"

WhiteLight::WhiteLight(std::string name, Vector2D pos) : Light(name, pos)
{
	this->addComponent(new Rectangle(this->pos + Vector2D(23.5, 48), Vector2D(17, 10), "destiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("destiny"), "WhiteLight.png", "StaticSprite"));
	this->addBehavior(new MoveBehavior("moveUPBehavior", Vector2D(0, 3), (Rectangle*)this->getComponent("destiny")));
}

WhiteLight::~WhiteLight()
{
}
