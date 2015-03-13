#pragma once

#include "GameState.h"

class PauseState : public GameState
{
public:
	PauseState();
	virtual ~PauseState();

	void execute_BTN2();
	void execute_BTN1();
	void execute_LEFT();
	void execute_RIGHT();
	void execute_UP();
	void execute_DOWN();
};
