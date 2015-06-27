#pragma once

#include "GameObject.h"
#include "StaticTextSprite.h"
#include "DynamicTextSprite.h"
#include "ColoredBackgroundSprite.h"
#include "Timers.h"

class Distance_HUD : public GameObject
{
public:
	Distance_HUD(std::string name, int milisecond_step, int distance_step);
	virtual ~Distance_HUD();

	void updateDistance();
	std::string formatOutput();
	void clear();
	std::string addZeros();
private:
	SlaveTimer* timer;
	unsigned long long int totalDistance;
	int milisecond_step;
	int distance_step;

	int distance;
	char distanceModifier;
};
