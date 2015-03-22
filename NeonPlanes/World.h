#pragma once

#include "MainMenuState.h"
#include "PauseState.h"
#include "PlayState.h"
#include "GameOverState.h"
#include "DebugState.h"

class World
{
public:
	World();
	virtual ~World();
	
	GameState* getCurrentState();
	void switchGameState(std::string state);
private:
	void addGameState(GameState* state);

	GameState* currentState;
	std::map<std::string, GameState*> map_states;
};
