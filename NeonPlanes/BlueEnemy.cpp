#include "BlueEnemy.h"

BlueEnemy::BlueEnemy(std::string name) : Enemy(name)
{
	this->addComponent(new Rectangle(Vector2D(280, 200), Vector2D(54, 55), "destiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("destiny"), "BlueEnemy.png", "StaticSprite"));
}

BlueEnemy::~BlueEnemy()
{
}

void BlueEnemy::shoot() {
	this->addPending(new BlueProjectile("whiteProjectile" + objectValue, ((Rectangle*)this->getComponent("destiny"))->getPosition()));
	if (objectValue >= LLONG_MAX) {
		this->objectValue = 0;
	}
	else {
		this->objectValue++;
	}
}

void BlueEnemy::useLightWall() {
	this->addPending(new BlueLight("whiteLight" + objectValue, ((Rectangle*)this->getComponent("destiny"))->getPosition()));
	if (objectValue >= LLONG_MAX) {
		this->objectValue = 0;
	}
	else {
		this->objectValue++;
	}
}