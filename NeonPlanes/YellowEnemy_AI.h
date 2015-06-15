#pragma once

#include "Base_AI.h"

class YellowEnemy_AI : public Base_AI
{
public:
	YellowEnemy_AI(GameObject* enemy, std::string name);
	virtual ~YellowEnemy_AI();

	void createTimers();
	void manageBehaviors();
};
