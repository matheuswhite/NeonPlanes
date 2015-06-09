#pragma once

#include "Behavior.h"

class DashBehavior : public Behavior
{
public:
	DashBehavior(std::string name);
	virtual ~DashBehavior();

	void run() override;
};
