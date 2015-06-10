#pragma once

#include "Behavior.h"

class TurnOffBehavior : public Behavior
{
public:
	TurnOffBehavior(Rectangle* destiny, float airplaneSize_y, bool* gameObject_Active, std::string name);
	virtual ~TurnOffBehavior();

	void run() override;
private:
	bool* gameObject_Active;
	float airplaneSize_y;
	Rectangle* destiny;
};
