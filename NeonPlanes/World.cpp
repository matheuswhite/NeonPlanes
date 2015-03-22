#include "World.h"

World::World()
{
	addGameState(new PlayState());
	addGameState(new MainMenuState());
	addGameState(new PauseState());
	addGameState(new GameOverState());

#if _DEBUG
	addGameState(new DebugState());
#endif //_DEBUG
}

World::~World()
{
}

GameState* World::getCurrentState() {
	return currentState;
}

void World::switchGameState(std::string state) {
	currentState = map_states.at(state);
}

void World::addGameState(GameState* state) {
	map_states.insert(std::pair< std::string, GameState* >(typeid(*state).name(), state));
}