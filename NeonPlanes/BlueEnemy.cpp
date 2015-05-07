#include "BlueEnemy.h"

BlueEnemy::BlueEnemy(std::string name) : Enemy(name)
{
	this->addComponent(new Rectangle(Vector2D(280, 200), Vector2D(64, 75), 0, "rectDestiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("rectDestiny"), "BlueEnemy.png", "blue"));
}

BlueEnemy::~BlueEnemy()
{
}