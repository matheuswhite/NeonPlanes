#pragma once

#include "State.h"

class FSM
{
public:
	FSM();
	FSM(std::set<State*> states);
	virtual ~FSM();

	void addState(State* state);
	void addTransition(State* first, State* second, std::pair<int, std::function<void(RedEnemy_AI&)> > transition);
	void switchState(int transition, RedEnemy_AI& ai);
	State* getState(int id);
	State* getCurentState() const;
private:
	std::set<State*> states;
	State* currentState;
};
