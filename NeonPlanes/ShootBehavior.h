#pragma once

#include "Behavior.h"

class ShootBehavior : public Behavior
{
public:
	ShootBehavior(std::string name);
	virtual ~ShootBehavior();

	void run() override;
};
