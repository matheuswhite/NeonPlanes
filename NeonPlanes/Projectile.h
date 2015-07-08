#pragma once

#include "GameObject.h"
#include "StaticSprite.h"
#include "MoveBehavior.h"
#include "TurnOffBehavior.h"

class Projectile : public GameObject
{
public:
	Projectile(std::string name, Vector2D pos);
	virtual ~Projectile();

protected:
	Vector2D pos;
};
