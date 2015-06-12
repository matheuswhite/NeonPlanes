#pragma once

#include "Enemy.h"
#include "RedProjectile.h"
#include "RedLight.h"

class RedEnemy : public Enemy
{
public:
	RedEnemy(std::string name, Rectangle* destiny);
	virtual ~RedEnemy();

	void shoot();
	void useLightWall();
private:

};
