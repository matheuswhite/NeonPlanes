#include "State.h"

State::State(int id, bool initialState) : id(id), initialState(initialState)
{
}

State::~State()
{
}

int State::getID() const {
	return this->id;
}

bool State::isInitalState() const {
	return this->initialState;
}

State* State::getState(int transition) {
	if (this->hasTransition(transition)) {
		return this->transitions.at(transition);
	}
	return nullptr;
}

std::function<void(RedEnemy_AI&)> State::getTransitionFunction(int transition) {
	if (this->hasTransition(transition)) {
		return this->trnsitions_functions.at(transition);
	}
	return nullptr;
}

void State::addState(State* state, std::pair<int, std::function<void(RedEnemy_AI&)> > transition) {
	if (!this->hasTransition(transition.first)) {
		this->transitions.insert(std::pair<int, State*>(transition.first, state));
		this->trnsitions_functions.insert(transition);
	}
}

bool State::hasTransition(int transition) {
	if (this->transitions.find(transition) != this->transitions.end()) {
		return true;
	}
	return false;
}