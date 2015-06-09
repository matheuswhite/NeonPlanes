#pragma once

#include "Airplane.h"
#include "WhiteProjectile.h"
#include "WhiteLight.h"
#include "PlayerMoveBehavior.h"

class Player : public Airplane
{
public:
	Player(std::string name);
	virtual ~Player();

	void shoot();
	void useLightWall();
	void move(Vector2D vel);
	Vector2D getCurrentVelocity();
};
