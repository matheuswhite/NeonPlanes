#pragma once

#include "Airplane.h"
#include "WhiteProjectile.h"
#include "WhiteLight.h"
#include "PlayerMoveBehavior.h"
#include "Light_HUD.h"

class Player : public Airplane
{
public:
	Player(std::string name, Light_HUD* light_HUD);
	virtual ~Player();

	void shoot();
	void useLightWall();
	void move(Vector2D vel);
	Vector2D getCurrentVelocity();

private:
	Light_HUD* light_HUD;
};
