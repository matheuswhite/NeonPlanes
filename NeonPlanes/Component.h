#pragma once

#include "core.h"

class Component
{
public:
	Component(std::string name) : name(name) {
		this->active = true;
	}

	virtual ~Component() { this->name.clear(); }

	bool isActive() const {
		return this->active;
	}

	std::string getName() const {
		return this->name;
	}
protected:
	void turnOff() { 
		this->active = false;
	}
	
	bool active;
	std::string name;
};