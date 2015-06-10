#pragma once

#include "Behavior.h"

class InitialEnemyBehavior : public Behavior
{
public:
	InitialEnemyBehavior(Behavior* initialBehavior, float velocity_x, Rectangle* destiny, float airplaneSize_x, std::string name);
	virtual ~InitialEnemyBehavior();

	void run() override;
private:
	Behavior* initialBehavior;
	Rectangle* destiny;
	float velocity_x;
	float airplaneSize_x;
};
