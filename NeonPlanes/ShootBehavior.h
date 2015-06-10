#pragma once

#include "Behavior.h"

class GameObject;

class ShootBehavior : public Behavior
{
public:
	ShootBehavior(std::string name, std::function<void(const GameObject&)> shootFunction, GameObject* enemy);
	virtual ~ShootBehavior();

	void run() override;
private:
	GameObject* enemy;
	std::function<void(const GameObject&)> shootFunction;
};
