#include "RedEnemy.h"

RedEnemy::RedEnemy(std::string name) : Enemy(name)
{
	this->addComponent(new Rectangle(Vector2D(195, 200), Vector2D(54, 55), "destiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("destiny"), "RedEnemy.png", "StaticSprite"));
}

RedEnemy::~RedEnemy()
{
}

void RedEnemy::shoot() {

}