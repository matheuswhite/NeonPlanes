#include "CheckerCollision.h"

CheckerCollision::CheckerCollision(std::vector<GameObject*>* objects) : objects(objects) {

}

CheckerCollision::~CheckerCollision() {
	this->objects->clear();
	this->airplanes.clear();
}

void CheckerCollision::addAirplanes(Airplane* airplane) {
	this->airplanes.push_back(airplane);
}

void CheckerCollision::checkCollisions() {
	auto objects = *this->objects;

	for each (auto airplane in this->airplanes)
	{
		for each (auto object in objects)
		{
			if (airplane->isActive() && object->isActive()) {
				this->collisionChekingAlgorithm(airplane, object);
			}
		}
	}
}

void CheckerCollision::collisionChekingAlgorithm(Airplane* airplane, GameObject* object) {
	
	if (airplane->hasComponent("destiny") && object->hasBehavior("destiny")) {
		
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
					
					utility::remove<Airplane*>(&this->airplanes, airplane);
					utility::remove<Airplane*>(&this->airplanes, (Airplane*)object);
				}
				else if (typeid(*object) == typeid(RedProjectile) ||
					     typeid(*object) == typeid(BlueProjectile) ||
					     typeid(*object) == typeid(YellowProjectile)) {
					airplane->active = false;
					object->active = false;

					utility::remove<Airplane*>(&this->airplanes, airplane);
				}
				else if (typeid(*object) == typeid(RedLight) ||
					     typeid(*object) == typeid(BlueLight) ||
					     typeid(*object) == typeid(YellowLight)) {
					airplane->active = false;

					utility::remove<Airplane*>(&this->airplanes, airplane);
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

					utility::remove<Airplane*>(&this->airplanes, airplane);
					utility::remove<Airplane*>(&this->airplanes, (Airplane*)object);
				}
				else if (typeid(*object) == typeid(WhiteProjectile)) {
					airplane->active = false;
					object->active = false;

					utility::remove<Airplane*>(&this->airplanes, airplane);
				}
				else if (typeid(*object) == typeid(WhiteLight)) {
					airplane->active = false;
					object->active = false;

					utility::remove<Airplane*>(&this->airplanes, airplane);
				}
			}
		}
	}
}