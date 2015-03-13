#pragma once

#include "Message.h"
#include "GameObject.h"

class Component
{
	//add friend class as filha. 
	//ex.: AI -> behavior
public:
	Component() {
		this->active = true;
	}
	virtual ~Component();

	bool isActive() const {
		return this->active;
	}
protected:
	void turnOff() { this->active = false; }
	
	bool active;
	GameObject* obj;
};