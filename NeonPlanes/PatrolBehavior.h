#pragma once

#include "Behavior.h"

class PatrolBehavior : public Behavior
{
public:
	PatrolBehavior(std::string name, float velocity_x, Rectangle* destiny, float airplaneSize_x);
	virtual ~PatrolBehavior();

	void run() override;
private:
	float velocity_x;
	Rectangle* destiny;
	float airplaneSize_x;
};
