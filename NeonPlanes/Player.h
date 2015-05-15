#pragma once

#include "GameObject.h"
#include "WhiteProjectile.h"

class Player : public GameObject
{
public:
	Player(std::string name);
	virtual ~Player();

	void shoot();
private:

};
