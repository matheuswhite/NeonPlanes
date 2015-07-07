#pragma once

#include "MainMenuState.h"
#include "PauseState.h"
#include "PlayState.h"
#include "GameOverState.h"
#include "HighscoreState.h"
#include "Notifier.h"

class World : public NotifierInterface
{
public:
	World();
	virtual ~World();
	
	GameState* getCurrentState();
	std::map<int, GameState*> getMapStates() const;
	void switchGameState(Uint8 state);

	void action(int parameter);
private:
	void addGameState(GameState* state);

	GameState* currentState;
	std::map<int, GameState*> map_states;

	bool clearGameWorld;
};
