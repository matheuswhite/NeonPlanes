#pragma once

#include "Behavior.h"

class GameObject;

class LightWallBehavior : public Behavior
{
public:
	LightWallBehavior(std::string name, std::function<void(const GameObject&)> lightWallFunction, GameObject* enemy);
	virtual ~LightWallBehavior();

	void run() override;
private:
	GameObject* enemy;
	std::function<void(const GameObject&)> lightWallFunction;
};
