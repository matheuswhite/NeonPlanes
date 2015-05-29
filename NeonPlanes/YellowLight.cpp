#include "YellowLight.h"

YellowLight::YellowLight(std::string name, Vector2D pos) : Light(name, pos)
{
	this->addComponent(new Rectangle(this->pos + Vector2D(18.5, 58), Vector2D(13, 10), "destiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("destiny"), "YellowLight.png", "StaticSprite"));
	this->addBehavior(new MoveBehavior("moveUPBehavior", Vector2D(0, 2), (Rectangle*)this->getComponent("destiny"), nullptr));
}

YellowLight::~YellowLight()
{
}
