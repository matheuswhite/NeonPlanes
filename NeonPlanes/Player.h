#pragma once

#include "GameObject.h"
#include "WhiteProjectile.h"
#include "WhiteLight.h"

class Player : public GameObject
{
public:
	Player(std::string name);
	virtual ~Player();

	void shoot();
	void useLightWall();
private:
	unsigned long long int objectValue;
};
