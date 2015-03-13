#pragma once

#include "Singleton.h"
#include "Command.h"

class GameState
{
public:
	GameState() {}
	virtual ~GameState() {}
	
	virtual void execute_A() = 0;
	virtual void execute_X() = 0;
	virtual void execute_B() = 0;
	virtual void execute_RB() = 0;
	virtual void execute_LB() = 0;
	virtual void execute_START() = 0;
	virtual void execute_BACK() = 0;
	virtual void execute_LEFT() = 0;
	virtual void execute_RIGHT() = 0;
	virtual void execute_UP() = 0;
	virtual void execute_DOWN() = 0;
};
