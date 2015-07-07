#pragma once

#include "GameState.h"
#include "FPS_HUD.h"
#include "Background.h"

#include "CheckerCollision.h"
#include "ObjectManager.h"
#include "LevelManager.h"

class PlayState : public GameState
{
public:
	PlayState();
	virtual ~PlayState();

	void execute_BTN_Z();
	void execute_BTN_SPACE();
	void execute_BTN_ENTER();
	void execute_LEFT();
	void execute_RIGHT();
	void execute_UP();
	void execute_DOWN();
	void stop(bool direction);
	void totalStop();

	LevelManager* getLevelManager() const;
	void createGameWorld();
	void destroyGameWorld();
	void runLevelLogic();
private:
	bool gameWorldCreated;
	LevelManager* level;
};
