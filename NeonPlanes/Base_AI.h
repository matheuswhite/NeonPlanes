#pragma once

#include "GameObject.h"
#include "Timers.h"

class Base_AI : public GameObject
{
public:
	Base_AI(GameObject* enemy, std::string name) : GameObject(name), enemy(enemy)
	{ 
		this->enemyBehaviors = enemy->getVectorBaheviors();
		auto initBehavior = enemy->getBehavior("InitialEnemyBehavior");
		((InitialEnemyBehavior*)initBehavior)->setFlagInitialize(&this->flagInitialize);

		this->createTimers();
	}
	virtual ~Base_AI() {}

	virtual void createTimers() = 0;
	virtual void manageBehaviors() = 0;
protected:
	bool flagInitialize;
	GameObject* enemy;
	std::vector<Behavior*> enemyBehaviors;
	std::vector<SlaveTimer*> timers;
};
