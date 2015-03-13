#include "World.h"

GameState* World::currentState = nullptr;
std::map< std::string, GameState* > World::map_states = {};

World::World()
{
	addGameState(new PlayState());
	addGameState(new MainMenuState());
	addGameState(new PauseState());
	addGameState(new GameOverState());

	this->currentState = new DebugState();
}

World::~World()
{
	delete this->currentState;
	this->currentState = nullptr;

	for (auto it = this->map_states.begin(); it != this->map_states.end(); ++it) {
		delete it->second;
		it->second = nullptr;
	}

	this->map_states.clear();
}

GameState* World::getCurrentState() {
	return currentState;
}

void World::switchGameState(std::string state) {
	currentState = map_states[state];
}

void World::addGameState(GameState* state) {
	map_states.insert(std::pair< std::string, GameState* >(typeid(*state).name(), state));
}