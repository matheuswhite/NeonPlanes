#pragma once

#include "core.h"
#include "GameObject.h"
#include "Airplane.h"

class Player;
class RedEnemy;
class BlueEnemy;
class YellowEnemy;

class WhiteProjectile;
class RedProjectile;
class BlueProjectile;
class YellowProjectile;

class WhiteLight;
class RedLight;
class BlueLight;
class YellowLight;

class CheckerCollision
{
public:
	CheckerCollision();
	virtual ~CheckerCollision();

	static void addAirplanes(Airplane* airplane);
	static void addObjects(std::vector<GameObject*> objects);
	static void checkCollisions();
	
	static bool containsObjects();
	static bool containsAirplanes();

private:
	static void collisionChekingAlgorithm(Airplane* airplane, GameObject* object, std::vector<GameObject*>* removed_GameObjects, std::vector<Airplane*>* removed_Airplanes);

	static std::vector<GameObject*> _objects;
	static std::vector<Airplane*> _airplanes;
};
