#include "MenuBehavior.h"

MenuBehavior::MenuBehavior(std::string name, std::vector<Behavior*> behaviors) : behaviors(behaviors), Behavior(name)
{
}

MenuBehavior::~MenuBehavior()
{
}

void MenuBehavior::run() {

	for each (auto var in this->behaviors)
	{
		var->run();
	}
}

void MenuBehavior::addBehavior(Behavior* behavior) {
	this->behaviors.push_back(behavior);
}