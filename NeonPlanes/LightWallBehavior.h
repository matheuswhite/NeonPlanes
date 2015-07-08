#pragma once

#include "Behavior.h"

class Enemy;

class LightWallBehavior : public Behavior
{
public:
	LightWallBehavior(std::string name, std::function<void(void)> lightWallFunction);
	virtual ~LightWallBehavior();

	void run() override;
private:
	std::function<void(void)> lightWallFunction;
};
