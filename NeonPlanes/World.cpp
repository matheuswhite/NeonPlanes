#include "World.h"

World::World()
{
	addGameState(new PlayState());
	addGameState(new MainMenuState());
	addGameState(new PauseState());
	addGameState(new GameOverState());
}

World::~World()
{
}

GameState* World::getCurrentState() {
	return currentState;
}

void World::switchGameState(Uint8 state) {
	currentState = map_states.at(state);

	if (state == utility::PLAY) {
		((PlayState*)currentState)->createGameWorld();
	}
	else if (state == utility::MAIN_MENU) {
		((PlayState*)currentState)->destroyGameWorld();
	}
}

void World::addGameState(GameState* state) {
	if (typeid(*state) == typeid(GameOverState))
		map_states.insert(std::pair< Uint8, GameState* >(utility::GAMEOVER, state));
	else if (typeid(*state) == typeid(PlayState))
		map_states.insert(std::pair< Uint8, GameState* >(utility::PLAY, state));
	else if (typeid(*state) == typeid(PauseState))
		map_states.insert(std::pair< Uint8, GameState* >(utility::PAUSE, state));
	else if (typeid(*state) == typeid(MainMenuState))
		map_states.insert(std::pair< Uint8, GameState* >(utility::MAIN_MENU, state));
}