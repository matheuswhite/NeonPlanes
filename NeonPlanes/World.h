#pragma once

#include "GameStateHeaders.h"

class World
{
public:
	World();
	virtual ~World();
	
	static GameState* getCurrentState();
	static void switchGameState(std::string state);
private:
	static void addGameState(GameState* state);

	static GameState* currentState;
	static std::map< std::string, GameState* > map_states;
};
