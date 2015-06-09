#pragma once

#include "Behavior.h"

class GoDownBehavior : public Behavior
{
public:
	GoDownBehavior(std::string name);
	virtual ~GoDownBehavior();

	void run() override;
};
