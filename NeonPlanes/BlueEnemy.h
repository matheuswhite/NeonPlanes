#pragma once

#include "Enemy.h"

class BlueEnemy : public Enemy
{
public:
	BlueEnemy(std::string name);
	virtual ~BlueEnemy();

	void shoot();
private:

};
