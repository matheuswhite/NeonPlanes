#pragma once

#include "Behavior.h"

class Enemy;

class ShootBehavior : public Behavior
{
public:
	ShootBehavior(std::string name, std::function<void(void)> shootFunction);
	virtual ~ShootBehavior();

	void run() override;
private:
	std::function<void(void)> shootFunction;
};
