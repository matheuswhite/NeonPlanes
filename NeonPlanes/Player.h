#pragma once

#include "GameObject.h"
#include "WhiteProjectile.h"
#include "WhiteLight.h"
#include "MoveBehavior.h"

class Player : public GameObject
{
public:
	Player(std::string name);
	virtual ~Player();

	void shoot();
	void useLightWall();
	void move(Vector2D vel);
	Vector2D getCurrentVelocity();

	float getVelocityValue() const;
private:
	unsigned long long int objectValue;
	float velocity;
};
