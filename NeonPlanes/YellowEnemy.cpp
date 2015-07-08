#include "YellowEnemy.h"

YellowEnemy::YellowEnemy(std::string name, Rectangle* destiny, float base_velocity) : Enemy(name, destiny, base_velocity)
{
	auto patrol = new PatrolBehavior("PatrolBehavior", base_velocity, (Rectangle*)this->getComponent("destiny"), ((Rectangle*)this->getComponent("destiny"))->getSize().x);

	//SPRITES
	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("destiny"), "YellowEnemy.png", "StaticSprite"));
	
	//BEHAVIORS
	this->addBehavior(new InitialEnemyBehavior(patrol, base_velocity / 2.5, (Rectangle*)this->getComponent("destiny"), ((Rectangle*)this->getComponent("destiny"))->getSize().x, "InitialEnemyBehavior"));
	
	this->addBehavior(patrol);
	this->getBehavior("PatrolBehavior")->setActive(false);

	this->addBehavior(new ShootBehavior("ShootBehavior", std::bind(&YellowEnemy::shoot, this)));
	this->getBehavior("ShootBehavior")->setActive(false);
}

YellowEnemy::~YellowEnemy()
{
}

void YellowEnemy::shoot() {
	if (this->testShoot()) {
		this->addPending(new YellowProjectile("YellowProjectile" + std::to_string(objectValue), ((Rectangle*)this->getComponent("destiny"))->getPosition()));
		if (objectValue >= LLONG_MAX) {
			this->objectValue = 0;
		}
		else {
			this->objectValue++;
		}
	}
}

void YellowEnemy::useLightWall() {
	this->addPending(new YellowLight("YellowLight" + std::to_string(objectValue), ((Rectangle*)this->getComponent("destiny"))->getPosition()));
	if (objectValue >= LLONG_MAX) {
		this->objectValue = 0;
	}
	else {
		this->objectValue++;
	}
}