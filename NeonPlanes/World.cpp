#include "World.h"

World::World()
{
	addGameState(new PlayState());
	addGameState(new MainMenuState());
	addGameState(new PauseState());
	addGameState(new GameOverState());
	addGameState(new HighscoreState());
	Notifier::addReciver(this);

	this->currentState = this->map_states.at(utility::states::MAIN_MENU);

	this->clearGameWorld = false;
}

World::~World()
{
}

GameState* World::getCurrentState() {
	return currentState;
}

std::map<int, GameState*> World::getMapStates() const {
	return this->map_states;
}

void World::switchGameState(Uint8 state) {
	auto prevState = currentState;
	currentState = map_states.at(state);

	if (state == utility::states::GAMEOVER) {
		auto trio = ((PlayState*)this->map_states.at(utility::PLAY))->getLevelManager()->getLevelDistanceTotal();
		((GameOverState*)this->map_states.at(utility::GAMEOVER))->updateValues(trio.first, trio.second.first, trio.second.second);
	}
	if (state == utility::PLAY) {
		((PlayState*)currentState)->createGameWorld();
		this->clearGameWorld = false;
	}
	if (prevState != nullptr) {
		if (state == utility::MAIN_MENU && (typeid(*prevState) == typeid(PauseState) || typeid(*prevState) == typeid(GameOverState))) {
			((PlayState*)this->map_states.at(utility::PLAY))->destroyGameWorld();
		}
	}

	if (state == utility::states::HIGHSCORE) {
		((HighscoreState*)this->map_states.at(utility::HIGHSCORE))->updateValues();
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
	else if (typeid(*state) == typeid(HighscoreState))
		map_states.insert(std::pair< Uint8, GameState* >(utility::HIGHSCORE, state));
}

void World::action(int parameter) {
	this->switchGameState(parameter);
}
