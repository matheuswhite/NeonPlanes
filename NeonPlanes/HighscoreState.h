#pragma once

#include "GameState.h"
#include "TextItem.h"
#include "DynamicTextItem.h"
#include "Background.h"
#include "FPS_HUD.h"
#include "DataStore.h"

class HighscoreState : public GameState
{
public:
	HighscoreState();
	virtual ~HighscoreState();

	void execute_BTN_Z();
	void execute_BTN_SPACE();
	void execute_BTN_ENTER();
	void execute_LEFT();
	void execute_RIGHT();
	void execute_UP();
	void execute_DOWN();

	void updateValues();
	std::vector<std::pair<std::string, std::string> > getHighscore();
};

