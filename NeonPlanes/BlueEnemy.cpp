#include "BlueEnemy.h"

BlueEnemy::BlueEnemy(Uint32 id, std::string name) : Enemy(id, name)
{
	this->addComponent(new Rectangle(Vector2D(280, 200), Vector2D(64, 75), 0, "rectDestiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("rectDestiny"), "BlueEnemy.png", "blue"));
}

BlueEnemy::~BlueEnemy()
{
}