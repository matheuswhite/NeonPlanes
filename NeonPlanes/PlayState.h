#pragma once

#include "GameState.h"
#include "FPS_HUD.h"
#include "Background.h"
#include "Player.h"
#include "BlueEnemy.h"
#include "RedEnemy.h"
#include "YellowEnemy.h"
#include "BlueProjectile.h"
#include "RedProjectile.h"
#include "YellowProjectile.h"
#include "WhiteProjectile.h"

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

	void createGameWorld();
private:
	bool gameWorldCreated;
};
