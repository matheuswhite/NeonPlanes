#include "YellowEnemy.h"

YellowEnemy::YellowEnemy(std::string name) : Enemy(name)
{
	this->addComponent(new Rectangle(Vector2D(100, 200), Vector2D(54, 55), 0, "rectDestiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("rectDestiny"), "YellowEnemy.png", "yellow"));
}

YellowEnemy::~YellowEnemy()
{
}