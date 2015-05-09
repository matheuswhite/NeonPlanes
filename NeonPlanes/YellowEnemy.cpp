#include "YellowEnemy.h"

YellowEnemy::YellowEnemy(std::string name) : Enemy(name)
{
	this->addComponent(new Rectangle(Vector2D(100, 200), Vector2D(54, 55), "destiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("destiny"), "YellowEnemy.png", "StaticSprite"));
}

YellowEnemy::~YellowEnemy()
{
}

void YellowEnemy::shoot() {

}