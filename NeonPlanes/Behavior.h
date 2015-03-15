#pragma once

#include "Component.h"

class Behavior : public Component
{
public:
	Behavior(GameObject* obj) : Component(obj) {}
	virtual ~Behavior() {}

	virtual void run() = 0;
};

