#include "RedEnemy.h"

RedEnemy::RedEnemy(std::string name, Rectangle* destiny) : Enemy(name, destiny)
{
	//this->addComponent(new Rectangle(Vector2D(195, 200), Vector2D(54, 55), "destiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("destiny"), "RedEnemy.png", "StaticSprite"));
}

RedEnemy::~RedEnemy()
{
}

void RedEnemy::shoot() {
	this->addPending(new RedProjectile("whiteProjectile" + objectValue, ((Rectangle*)this->getComponent("destiny"))->getPosition()));
	if (objectValue >= LLONG_MAX) {
		this->objectValue = 0;
	}
	else {
		this->objectValue++;
	}
}

void RedEnemy::useLightWall() {
	this->addPending(new RedLight("whiteLight" + objectValue, ((Rectangle*)this->getComponent("destiny"))->getPosition()));
	if (objectValue >= LLONG_MAX) {
		this->objectValue = 0;
	}
	else {
		this->objectValue++;
	}
}