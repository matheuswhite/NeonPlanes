#pragma once

#include "GameObject.h"

class Airplane : public GameObject
{
public:
	Airplane(std::string name) : collided(false), collided_IAFlag(false), objectValue(0), GameObject(name) {}
	virtual ~Airplane() {}

	virtual void shoot() = 0;
	virtual void useLightWall() = 0;

	bool isCollided() const { return this->collided; }

	float getVelocityValue() const { return this->velocity; }
protected:
	friend class CheckerCollision;

	bool collided;
	bool collided_IAFlag;
	unsigned long long int objectValue;
	float velocity;
};
