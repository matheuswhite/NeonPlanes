#include "RedEnemy.h"

RedEnemy::RedEnemy(Uint32 id, std::string name) : Enemy(id, name)
{
	this->addComponent(new Rectangle(Vector2D(195, 200), Vector2D(64, 75), 0, "rectDestiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("rectDestiny"), "RedEnemy.png", "red"));
}

RedEnemy::~RedEnemy()
{
}