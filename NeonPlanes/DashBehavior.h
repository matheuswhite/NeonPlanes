#pragma once

#include "Behavior.h"

class DashBehavior : public Behavior
{
public:
	DashBehavior(std::string name, float velocityDash_y, Rectangle* destiny, float airplaneSize_y);
	virtual ~DashBehavior();

	void run() override;
private:
	float velocityDash_y;
	Rectangle* destiny;
	float airplaneSize_y;
};
