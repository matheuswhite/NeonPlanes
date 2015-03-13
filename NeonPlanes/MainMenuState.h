#pragma once

#include "GameState.h"

class MainMenuState : public GameState
{
public:
	MainMenuState();
	virtual ~MainMenuState();

	void execute_BTN1();
	void execute_BTN2();
	void execute_LEFT();
	void execute_RIGHT();
	void execute_UP();
	void execute_DOWN();
};
