#include "YellowEnemy.h"

YellowEnemy::YellowEnemy(std::string name, Rectangle* destiny) : Enemy(name, destiny)
{
	auto patrol = new PatrolBehavior("PatrolBehavior", 4, (Rectangle*)this->getComponent("destiny"), ((Rectangle*)this->getComponent("destiny"))->getSize().x);

	//SPRITES
	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("destiny"), "YellowEnemy.png", "StaticSprite"));
	
	//BEHAVIORS
	this->addBehavior(new InitialEnemyBehavior(patrol, 1.5, (Rectangle*)this->getComponent("destiny"), ((Rectangle*)this->getComponent("destiny"))->getSize().x, "InitialEnemyBehavior"));
	
	this->addBehavior(patrol);
	this->getBehavior("PatrolBehavior")->setActive(false);

	this->addBehavior(new ShootBehavior("ShootBehavior", std::bind(&YellowEnemy::shoot, this)));
	this->getBehavior("ShootBehavior")->setActive(false);
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