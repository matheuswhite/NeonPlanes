#pragma once

#include "Enemy.h"
#include "BlueProjectile.h"
#include "BlueLight.h"

class BlueEnemy : public Enemy
{
public:
	BlueEnemy(std::string name);
	virtual ~BlueEnemy();

	void shoot();
	void useLightWall();
private:

};
