#pragma once

#include "MainMenuState.h"
#include "PauseState.h"
#include "PlayState.h"
#include "GameOverState.h"

class World
{
public:
	World();
	virtual ~World();
	
	GameState* getCurrentState();
	void switchGameState(Uint8 state);
private:
	void addGameState(GameState* state);

	GameState* currentState;
	std::map<int, GameState*> map_states;
};
