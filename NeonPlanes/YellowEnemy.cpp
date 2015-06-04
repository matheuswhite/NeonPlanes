#include "YellowEnemy.h"

YellowEnemy::YellowEnemy(std::string name) : Enemy(name)
{
	this->addComponent(new Rectangle(Vector2D(100, 200), Vector2D(54, 55), "destiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("destiny"), "YellowEnemy.png", "StaticSprite"));
	this->addBehavior(new AirplaneMoveBehavior("moveBehavior", Vector2D(0, 0), (Rectangle*)this->getComponent("destiny"), Vector2D(54, 55)));
}

YellowEnemy::~YellowEnemy()
{
}

void YellowEnemy::shoot() {
	this->addPending(new YellowProjectile("whiteProjectile" + objectValue, ((Rectangle*)this->getComponent("destiny"))->getPosition()));
	if (objectValue >= LLONG_MAX) {
		this->objectValue = 0;
	}
	else {
		this->objectValue++;
	}
}

void YellowEnemy::useLightWall() {
	this->addPending(new YellowLight("whiteLight" + objectValue, ((Rectangle*)this->getComponent("destiny"))->getPosition()));
	if (objectValue >= LLONG_MAX) {
		this->objectValue = 0;
	}
	else {
		this->objectValue++;
	}
}