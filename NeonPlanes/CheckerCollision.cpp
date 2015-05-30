#include "CheckerCollision.h"

std::vector<GameObject*>* CheckerCollision::_objects = nullptr;
std::vector<Airplane*> CheckerCollision::_airplanes;

CheckerCollision::CheckerCollision() {
}

CheckerCollision::~CheckerCollision() {
	this->_airplanes.clear();
}

bool CheckerCollision::containsObjects() {
	return ( (_objects != nullptr) && !(_objects->empty()) );
}

bool CheckerCollision::containsAirplanes() {
	return !(_airplanes.empty());
}

void CheckerCollision::addAirplanes(Airplane* airplane) {
	_airplanes.push_back(airplane);
}

void CheckerCollision::addObjects(std::vector<GameObject*> objects) {
	_objects = new std::vector<GameObject*>(objects);
}

void CheckerCollision::checkCollisions() {
	auto objects = *_objects;

	for each (auto airplane in _airplanes)
	{
		for each (auto object in objects)
		{
			if (airplane->isActive() && object->isActive()) {
				collisionChekingAlgorithm(airplane, object);
			}
		}
	}
}

void CheckerCollision::collisionChekingAlgorithm(Airplane* airplane, GameObject* object) {
	
	if (airplane->hasComponent("destiny") && object->hasComponent("destiny")) {
		
		auto airplaneRect = (Rectangle*)airplane->getComponent("destiny");
		auto objectRect = (Rectangle*)object->getComponent("destiny");

		if (airplaneRect->intersects(objectRect) || objectRect->intersects(airplaneRect)) {
			//player
			if (typeid(*airplane) == typeid(Player)) {
				if (typeid(*object) == typeid(Bounds)) {
					airplane->collided = true;
				}
				else if (typeid(*object) == typeid(RedEnemy) ||
					     typeid(*object) == typeid(BlueEnemy) ||
					     typeid(*object) == typeid(YellowEnemy)) {
					airplane->active = false;
					object->active = false;
					
					utility::remove<Airplane*>(&_airplanes, airplane);
					utility::remove<Airplane*>(&_airplanes, (Airplane*)object);
				}
				else if (typeid(*object) == typeid(RedProjectile) ||
					     typeid(*object) == typeid(BlueProjectile) ||
					     typeid(*object) == typeid(YellowProjectile)) {
					airplane->active = false;
					object->active = false;

					utility::remove<Airplane*>(&_airplanes, airplane);
				}
				else if (typeid(*object) == typeid(RedLight) ||
					     typeid(*object) == typeid(BlueLight) ||
					     typeid(*object) == typeid(YellowLight)) {
					airplane->active = false;

					utility::remove<Airplane*>(&_airplanes, airplane);
				}
			}
			//enemies
			else {
				if (typeid(*object) == typeid(Bounds)) {
					airplane->collided = true;
					airplane->collided_IAFlag = false;
				}
				else if (typeid(*object) == typeid(Player)) {
					airplane->active = false;
					object->active = false;

					utility::remove<Airplane*>(&_airplanes, airplane);
					utility::remove<Airplane*>(&_airplanes, (Airplane*)object);
				}
				else if (typeid(*object) == typeid(WhiteProjectile)) {
					airplane->active = false;
					object->active = false;

					utility::remove<Airplane*>(&_airplanes, airplane);
				}
				else if (typeid(*object) == typeid(WhiteLight)) {
					airplane->active = false;
					object->active = false;

					utility::remove<Airplane*>(&_airplanes, airplane);
				}
			}
		}
	}
}