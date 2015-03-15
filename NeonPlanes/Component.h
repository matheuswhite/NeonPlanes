#pragma once

class GameObject;

class Component
{
public:
	Component(GameObject* obj) {
		this->obj = obj;
		this->active = true;
	}
	virtual ~Component() {}

	bool isActive() const {
		return this->active;
	}
protected:
	void turnOff() { this->active = false; }
	
	bool active;
	GameObject* obj;
};