#pragma once

#include "Component.h"

class Sprite : public Component
{
public:
	Sprite(GameObject* obj) : Component(obj) {}
	virtual ~Sprite() {}

	virtual void draw() = 0;
};

