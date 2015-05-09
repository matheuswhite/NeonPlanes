#pragma once

#include "Enemy.h"

class YellowEnemy : public Enemy
{
public:
	YellowEnemy(std::string name);
	virtual ~YellowEnemy();
	
	void shoot();
private:

};
