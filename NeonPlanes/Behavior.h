#pragma once

#include "Component.h"

class Behavior : public Component
{
public:
	Behavior(std::string name) : Component(name) {}
	virtual ~Behavior() {}

	virtual void run() = 0;
};
