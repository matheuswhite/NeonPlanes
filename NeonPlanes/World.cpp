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
	for (auto it = this->map_states.begin(); it != this->map_states.end(); ++it) {
		delete it->second;
	}

	this->map_states.clear();
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