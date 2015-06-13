#pragma once

#include "GameObject.h"
#include "StaticSprite.h"
#include "Airplane.h"
#include "DashBehavior.h"
#include "GoDownBehavior.h"
#include "InitialEnemyBehavior.h"
#include "LightWallBehavior.h"
#include "PatrolBehavior.h"
#include "ShootBehavior.h"

class Enemy : public Airplane
{
public:
	Enemy(std::string name, Rectangle* destiny) : shoot251_Value(0), Airplane(name) {
		this->addComponent(destiny);

		shoot251_Flag[0] = true;
		shoot251_Flag[1] = false;
		shoot251_Flag[2] = false;

		for (size_t i = 0; i < 3; i++)
		{
			randMaxValue[i] = rand() % 10 + 1;
		}
	}
	virtual ~Enemy() {}

	virtual void shoot() = 0;
	virtual void useLightWall() = 0;
	
	bool testShoot() {
		if (shoot251_Flag[0] && !shoot251_Flag[1] && !shoot251_Flag[2]) {
			if (shoot251_Value >= randMaxValue[0]) {
				shoot251_Value = 0;
				shoot251_Flag[0] = false;
				shoot251_Flag[1] = true;

				return false;
			}
			else {
				shoot251_Value++;

				return true;
			}
		}
		else if (!shoot251_Flag[0] && shoot251_Flag[1] && !shoot251_Flag[2]) {
			if (shoot251_Value >= randMaxValue[1]) {
				shoot251_Value = 0;
				shoot251_Flag[1] = false;
				shoot251_Flag[2] = true;

				return false;
			}
			else {
				shoot251_Value++;
				
				return true;
			}
		}
		else if (!shoot251_Flag[0] && !shoot251_Flag[1] && shoot251_Flag[2]) {
			if (shoot251_Value >= randMaxValue[2]) {
				shoot251_Value = 0;
				shoot251_Flag[2] = false;
				shoot251_Flag[0] = true;

				for (size_t i = 0; i < 3; i++)
				{
					randMaxValue[i] = rand() % 10 + 1;
				}

				return false;
			}
			else {
				shoot251_Value++;

				return true;
			}
		}
		else {
			shoot251_Flag[0] = true;
			shoot251_Flag[1] = false;
			shoot251_Flag[2] = false;

			for (size_t i = 0; i < 3; i++)
			{
				randMaxValue[i] = rand() % 10 + 1;
			}

			return false;
		}
	}

private:
	bool shoot251_Flag[3];
	int shoot251_Value;
	int randMaxValue[3];
};
