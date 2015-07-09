#include "YellowEnemy_AI.h"

YellowEnemy_AI::YellowEnemy_AI(GameObject* enemy, std::string name) : Base_AI(enemy, name)
{
	this->createTimers();
}

YellowEnemy_AI::~YellowEnemy_AI()
{
}

void YellowEnemy_AI::createTimers() {
	this->addTimer(new SlaveTimer(1500,"ShootActive"));
	this->getTimer("ShootActive")->pause();

	this->addTimer(new SlaveTimer(2000, "ShootDisabled"));
	this->getTimer("ShootDisabled")->pause();
}

void YellowEnemy_AI::manageBehaviors() {
	if (!this->enemy->isActive()) {
		this->enemy = nullptr;
		this->active = false;
	}
	else {
		if (this->flagInitialize)
		{
			this->getTimer("ShootDisabled")->loop();
			this->flagInitialize = false;
		}

		if (this->getTimer("ShootDisabled")->isFinish())
		{
			this->getTimer("ShootDisabled")->loop();
			this->getTimer("ShootActive")->loop();

			this->getTimer("ShootDisabled")->pause();

			this->enemy->getBehavior("ShootBehavior")->setActive(true);
		}

		if (this->getTimer("ShootActive")->isFinish())
		{
			this->getTimer("ShootDisabled")->loop();
			this->getTimer("ShootActive")->loop();

			this->getTimer("ShootActive")->pause();

			this->enemy->getBehavior("ShootBehavior")->setActive(false);
		}
	}
}
