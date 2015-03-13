#pragma once

#include "GameState.h"

class PlayState : public GameState
{
public:
	PlayState();
	virtual ~PlayState();

	void execute_A();
	void execute_X();
	void execute_B();
	void execute_RB();
	void execute_LB();
	void execute_START();
	void execute_BACK();
	void execute_LEFT();
	void execute_RIGHT();
	void execute_UP();
	void execute_DOWN();
};
