#pragma once

#include "GameObject.h"
#include "StaticTextSprite.h"
#include "DynamicTextSprite.h"
#include "Timers.h"

class Light_HUD : public GameObject
{
public:
	Light_HUD(std::string name);
	virtual ~Light_HUD();

	void updateLightLevel();

	void setDecrease(bool* isDecrease);
	bool* getIsDecrease() const;
	bool isLightLevelPositive();
	void decreaseLightLevel();
	void fillLightLevel();
	std::string formatOutput();
private:
	bool* isDecrease;
	
	int lightLevel;
	SlaveTimer* decreaseTimer;
};
