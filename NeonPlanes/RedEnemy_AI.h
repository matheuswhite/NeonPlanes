#pragma once

#include "Base_AI.h"
#include "FSM.h"

class RedEnemy_AI : public Base_AI
{
public:
	RedEnemy_AI(GameObject* enemy, std::string name);
	virtual ~RedEnemy_AI();

	void createTimers();
	void manageBehaviors();
private:
	enum States
	{
		MIN_PATROL,
		LIGHT_WALL,
		GO_DOWN,
		DASH_AND_LIGHT_WALL,
		MAX_PATROL
	};

	enum Transitions
	{
		A,
		B,
		C
	};

	void initFSM();

	FSM* fsm;
	std::queue<Uint8> fita__;
};
