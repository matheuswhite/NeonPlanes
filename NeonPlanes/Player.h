#pragma once

#include "AirPlane.h"
#include "WhiteProjectile.h"

class Player : public AirPlane
{
public:
	Player(std::string name);
	virtual ~Player();

	void shoot();
private:

};
