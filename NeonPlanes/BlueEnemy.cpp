#include "BlueEnemy.h"

BlueEnemy::BlueEnemy(std::string name) : Enemy(name)
{
	this->addComponent(new Rectangle(Vector2D(280, 200), Vector2D(54, 55), "rectDestiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("rectDestiny"), "BlueEnemy.png", "blue"));
}

BlueEnemy::~BlueEnemy()
{
}

void BlueEnemy::shoot() {

}