#pragma once

#include "Enemy.h"
#include "YellowProjectile.h"
#include "YellowLight.h"

class YellowEnemy : public Enemy
{
public:
	YellowEnemy(std::string name, Rectangle* destiny);
	virtual ~YellowEnemy();
	
	void shoot();
	void useLightWall();
private:

};
