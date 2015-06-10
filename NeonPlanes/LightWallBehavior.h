#pragma once

#include "Behavior.h"

class LightWallBehavior : public Behavior
{
public:
	LightWallBehavior(std::string name);
	virtual ~LightWallBehavior();

	void run() override;
};
