#pragma once

#include "GameState.h"
#include "FPS_HUD.h"
#include "Background.h"

#include "Player.h"
#include "BlueEnemy.h"
#include "RedEnemy.h"
#include "YellowEnemy.h"

#include "YellowEnemy_AI.h"
#include "RedEnemy_AI.h"

#include "CheckerCollision.h"
#include "ObjectManager.h"

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

	void createGameWorld();
	void destroyGameWorld();
private:
	bool gameWorldCreated;
};
