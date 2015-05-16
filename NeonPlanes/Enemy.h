#pragma once

#include "GameObject.h"
#include "StaticSprite.h"

class Enemy : public GameObject
{
public:
	Enemy(std::string name);
	virtual ~Enemy();

protected:
	unsigned long long int objectValue;
};
