#pragma once

#include "Behavior.h"

class MenuBehavior : public Behavior
{
public:
	MenuBehavior(std::string name, std::vector<Behavior*> behaviors);
	virtual ~MenuBehavior();

	void run();

	void addBehavior(Behavior* behavior);
private:
	std::vector<Behavior*> behaviors;
};

