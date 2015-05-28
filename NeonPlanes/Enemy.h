#pragma once

#include "GameObject.h"
#include "StaticSprite.h"
#include "Airplane.h"

class Enemy : public Airplane
{
public:
	Enemy(std::string name) : Airplane(name) {}
	virtual ~Enemy() {}

	virtual void shoot() = 0;
	virtual void useLightWall() = 0;
};
