#pragma once

class Component
{
public:
	Component() {
		this->active = true;
	}

	virtual ~Component() {}

	bool isActive() const {
		return this->active;
	}
protected:
	void turnOff() { 
		this->active = false;
	}
	
	bool active;
};