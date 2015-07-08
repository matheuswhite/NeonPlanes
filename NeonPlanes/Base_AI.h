#pragma once

#include "GameObject.h"
#include "Timers.h"
#include "InitialEnemyBehavior.h"

class Base_AI : public GameObject
{
public:
	Base_AI(GameObject* enemy, std::string name) : GameObject(name), enemy(enemy)
	{ 
		auto initBehavior = enemy->getBehavior("InitialEnemyBehavior");
		((InitialEnemyBehavior*)initBehavior)->setFlagInitialize(&this->flagInitialize);
	}
	virtual ~Base_AI() {}

	virtual void createTimers() = 0;
	virtual void manageBehaviors() = 0;

protected:
	bool hasTimer(std::string name) {
		if (this->timers.find(name) != this->timers.end()) {
			return true;
		}
		return false;
	}

	SlaveTimer* getTimer(std::string name)
	{
		if (this->hasTimer(name)) {
			return this->timers.at(name);
		}

		return nullptr;
	}

	void addTimer(SlaveTimer* timer)
	{
		if (!this->hasTimer(name)) {
			this->timers.insert(std::pair<std::string, SlaveTimer*>(timer->getName(), timer));
		}
	}

	bool flagInitialize;
	GameObject* enemy;
	std::map<std::string, SlaveTimer*> timers;
};
