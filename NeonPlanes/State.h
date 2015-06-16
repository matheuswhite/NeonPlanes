#pragma once

#include "core.h"

class RedEnemy_AI;

class State
{
public:
	State(int id, bool initial);
	virtual ~State();

	int getID() const;
	bool isInitalState() const;

	void addState(State* state, std::pair<int, std::function<void(RedEnemy_AI&)> > transition);
	State* getState(int transition);
	std::function<void(RedEnemy_AI&)> getTransitionFunction(int transition);
private:
	bool hasTransition(int transition);

	const bool initialState;
	const int id;
	std::map<int, State*> transitions;
	std::map<int, std::function<void(RedEnemy_AI&)> > trnsitions_functions;
};
