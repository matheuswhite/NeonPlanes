#pragma once

#include "Command.h"

class GameState
{
public:
	GameState() {}
	virtual ~GameState() {}
	
	virtual void execute_BTN2() = 0;
	virtual void execute_BTN1() = 0;
	virtual void execute_LEFT() = 0;
	virtual void execute_RIGHT() = 0;
	virtual void execute_UP() = 0;
	virtual void execute_DOWN() = 0;
};
