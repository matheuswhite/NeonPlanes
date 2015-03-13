#pragma once

#include "Component.h"

class Behavior : public Component
{
public:
	Behavior();
	virtual ~Behavior();

	virtual void run() = 0;
};

