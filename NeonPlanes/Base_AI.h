#pragma once

#include "GameObject.h"
#include "Timers.h"

class Base_AI : public GameObject
{
public:
	Base_AI(GameObject* enemy, std::string name) : GameObject(name), enemy(enemy)
	{ 
		this->enemyBehaviors = enemy->getVectorBaheviors();
	}
	virtual ~Base_AI() {}

	virtual void manageBehaviors() = 0;
protected:
	GameObject* enemy;
	std::vector<Behavior*> enemyBehaviors;
	std::vector<SlaveTimer*> timers;
};
