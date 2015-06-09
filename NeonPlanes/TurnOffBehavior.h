#pragma once

#include "Behavior.h"

class TurnOffBehavior : public Behavior
{
public:
	TurnOffBehavior(std::string name);
	virtual ~TurnOffBehavior();

	void run() override;
};
