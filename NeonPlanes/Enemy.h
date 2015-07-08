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
	Enemy(std::string name, Rectangle* destiny, float base_velocity) : shoot251_Flag(true), shoot251_Value(0), base_velocity(base_velocity), Airplane(name) {
		this->addComponent(destiny);
	}
	virtual ~Enemy() {}

	virtual void shoot() = 0;
	virtual void useLightWall() = 0;
	
	bool testShoot() {
		if (shoot251_Flag) {
			if (shoot251_Value >= interval_value) {
				shoot251_Flag = !shoot251_Flag;
				shoot251_Value = 0;

				return true;
			}
			else {
				shoot251_Value++;
				
				return false;
			}
		}
		else {
			if (shoot251_Value >= interval_value * 15) {
				shoot251_Flag = !shoot251_Flag;
				shoot251_Value = 0;

				return true;
			}
			else {
				shoot251_Value++;

				return false;
			}
		}
	}

	void setBase_Velocity(float base_velocity) { this->base_velocity = base_velocity; }
private:
	bool shoot251_Flag;
	int shoot251_Value;
	const int interval_value = 3;

protected:
	float base_velocity;
};
