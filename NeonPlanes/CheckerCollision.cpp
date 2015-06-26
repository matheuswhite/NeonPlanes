#include "CheckerCollision.h"

std::vector<GameObject*> CheckerCollision::_objects;
std::vector<Airplane*> CheckerCollision::_airplanes;

CheckerCollision::CheckerCollision() {
}

CheckerCollision::~CheckerCollision() {
	this->_airplanes.clear();
}

bool CheckerCollision::containsObjects() {
	return !(_objects.empty());
}

bool CheckerCollision::containsAirplanes() {
	return !(_airplanes.empty());
}

void CheckerCollision::addAirplanes(Airplane* airplane) {
	_airplanes.push_back(airplane);
}

void CheckerCollision::clearObjects() {
	_airplanes.clear();
	_objects.clear();
}

void CheckerCollision::addObjects(std::vector<GameObject*> objects) {
	_objects.insert(_objects.end(), objects.begin(), objects.end());
}

void CheckerCollision::addObject(GameObject* object) {
	_objects.push_back(object);
}

void CheckerCollision::checkCollisions() {
	std::vector<GameObject*> removed_GameObjects;
	std::vector<Airplane*> removed_Airplanes;

	for each (auto airplane in _airplanes)
	{
		for each (auto object in _objects)
		{
			if (airplane->isActive() && object->isActive()) {
				collisionChekingAlgorithm(airplane, object, &removed_GameObjects, &removed_Airplanes);
			}
			else {
				if (!airplane->isActive()) {
					removed_Airplanes.push_back(airplane);
				}
				if (!object->isActive()) {
					removed_GameObjects.push_back(object);
				}
			}
		}
	}

	if (!removed_GameObjects.empty()) {
		for each (auto object in removed_GameObjects)
		{
			utility::remove<GameObject*>(&_objects, object);
		}
	}

	if (!removed_Airplanes.empty()) {
		for each (auto airplane in removed_Airplanes)
		{
			utility::remove<Airplane*>(&_airplanes, airplane);
		}
	}
}

void CheckerCollision::collisionChekingAlgorithm(Airplane* airplane, GameObject* object, std::vector<GameObject*>* removed_GameObjects, std::vector<Airplane*>* removed_Airplanes) {
	
	if (airplane->hasComponent("destiny") && object->hasComponent("destiny")) {
		
		auto airplaneRect = (Rectangle*)airplane->getComponent("destiny");
		auto objectRect = (Rectangle*)object->getComponent("destiny");

		if (airplaneRect->intersects(objectRect) || objectRect->intersects(airplaneRect)) {
			//player
			if (typeid(*airplane) == typeid(Player)) {
				if (typeid(*object) == typeid(RedEnemy) ||
					     typeid(*object) == typeid(BlueEnemy) ||
					     typeid(*object) == typeid(YellowEnemy)) {
					airplane->active = false;
					object->active = false;
					
					removed_Airplanes->push_back(airplane);
					removed_GameObjects->push_back(airplane);

					removed_Airplanes->push_back((Airplane*)object);
					removed_GameObjects->push_back(object);
				}
				else if (typeid(*object) == typeid(RedProjectile) ||
					     typeid(*object) == typeid(BlueProjectile) ||
					     typeid(*object) == typeid(YellowProjectile)) {
					airplane->active = false;
					object->active = false;

					removed_Airplanes->push_back(airplane);
					removed_GameObjects->push_back(airplane);

					removed_GameObjects->push_back(object);
				}
				else if (typeid(*object) == typeid(RedLight) ||
					     typeid(*object) == typeid(BlueLight) ||
					     typeid(*object) == typeid(YellowLight)) {
					airplane->active = false;
					
					removed_Airplanes->push_back(airplane);
					removed_GameObjects->push_back(airplane);
				}
			}
			//enemies
			else {
				if (typeid(*object) == typeid(Player)) {
					airplane->active = false;
					object->active = false;

					removed_Airplanes->push_back(airplane);
					removed_GameObjects->push_back(airplane);

					removed_Airplanes->push_back((Airplane*)object);
					removed_GameObjects->push_back(object);
				}
				else if (typeid(*object) == typeid(WhiteProjectile)) {
					airplane->active = false;
					object->active = false;

					std::cout << "collided projectile" << std::endl;

					removed_Airplanes->push_back(airplane);
					removed_GameObjects->push_back(airplane);

					removed_GameObjects->push_back(object);
				}
				else if (typeid(*object) == typeid(WhiteLight)) {
					airplane->active = false;

					std::cout << "collided light" << std::endl;
					
					removed_Airplanes->push_back(airplane);
					removed_GameObjects->push_back(airplane);
				}
			}
		}
	}
}