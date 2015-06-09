#pragma once

#include "GameObject.h"
#include "Timers.h"

class Base_IA : public GameObject
{
public:
	Base_IA(GameObject* enemy, std::string name) : GameObject(name), enemy(enemy)
	{ 
		this->enemyBehaviors = enemy->getVectorBaheviors();
	}
	virtual ~Base_IA() {}

	virtual void manageBehaviors() = 0;
protected:
	GameObject* enemy;
	std::vector<Behavior*> enemyBehaviors;
	std::vector<SlaveTimer*> timers;
};
