#pragma once

#include "GameObject.h"
#include "StaticSprite.h"
#include "Airplane.h"
#include "DashBehavior.h"
#include "GoDownBehavior.h"
#include "InitialEnemyBehavior.h"
#include "LightWallBehavior.h"
#include "PatrolBehavior.h"
#include "ShootBehavior.h"

class Enemy : public Airplane
{
public:
	Enemy(std::string name, Rectangle* destiny) : Airplane(name) { this->addComponent(destiny); }
	virtual ~Enemy() {}

	virtual void shoot() = 0;
	virtual void useLightWall() = 0;
};
