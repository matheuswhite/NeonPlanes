#pragma once

#include "GameObject.h"

class Item : public GameObject
{
public:
	Item(std::string name) : GameObject(name) {}
	virtual ~Item() {}

	virtual void highlight() {}
	virtual void turnOff() {}
};
