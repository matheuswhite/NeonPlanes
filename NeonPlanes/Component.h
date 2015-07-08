#pragma once

#include "core.h"

class Component
{
public:
	Component(std::string name, bool active = true) : name(name) {
		this->active = active;
	}

	virtual ~Component() { this->name.clear(); }

	bool isActive() const {
		return this->active;
	}

	std::string getName() const {
		return this->name;
	}

	void setActive(bool val) {
		this->active = val;
	}
protected:
	bool active;
	std::string name;
};