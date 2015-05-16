#pragma once

#include "Enemy.h"
#include "YellowProjectile.h"
#include "YellowLight.h"

class YellowEnemy : public Enemy
{
public:
	YellowEnemy(std::string name);
	virtual ~YellowEnemy();
	
	void shoot();
	void useLightWall();
private:

};
