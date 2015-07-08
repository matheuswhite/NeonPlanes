#pragma once

#include "Behavior.h"

class GoDownBehavior : public Behavior
{
public:
	GoDownBehavior(std::string name, float velocityGoDown_y, Rectangle* destiny, float airplaneSize_y);
	virtual ~GoDownBehavior();

	void run() override;
private:
	float velocityGoDown_y;
	Rectangle* destiny;
	float airplaneSize_y;
};
