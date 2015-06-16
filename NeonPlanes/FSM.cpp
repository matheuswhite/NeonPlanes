#include "FSM.h"

FSM::FSM()
{
	this->currentState = nullptr;
}

FSM::FSM(std::set<State*> states) : states(states)
{
	this->currentState = nullptr;
}

FSM::~FSM()
{
}

void FSM::addState(State* state) {
	if (this->currentState != nullptr && state->isInitalState()) {
		std::cerr << "ERROr: Initaial state already was added!" << std::endl;
		return;
	}
	if (this->states.find(state) == this->states.end()) {
		this->states.insert(state);
		if (state->isInitalState()) {
			this->currentState = state;
		}
	}
}

void FSM::addTransition(State* first, State* second, std::pair<int, std::function<void(RedEnemy_AI&)> > transition) {
	first->addState(second, transition);
}

void FSM::switchState(int transition, RedEnemy_AI& ai) {
	auto func = this->currentState->getTransitionFunction(transition);
	func(ai);
	auto state = this->currentState->getState(transition);
	this->currentState = state;
}

State* FSM::getState(int id) {
	for each (auto var in this->states)
	{
		if (var->getID() == id) {
			return var;
		}
	}

	return nullptr;
}

State* FSM::getCurentState() const {
	return this->currentState;
}