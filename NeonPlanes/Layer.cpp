#include "Layer.h"


Layer::Layer(std::string name)
{
	this->name = name;
}

Layer::~Layer()
{
}

void Layer::addGameObject(GameObject* obj) 
{
	this->map_objects.insert(std::pair<std::string, GameObject*>(obj->getName(), obj));
	this->objects.push_back(obj);
}

GameObject* Layer::getGameObject(std::string obj) const 
{ 
	return this->map_objects.at(obj); 
}

std::vector<GameObject*> Layer::getGameObjects() const 
{ 
	return this->objects; 
}

std::string Layer::getName() const {
	return this->name;
}

void Layer::addPending() {
	std::vector< std::vector<GameObject*> > tempVector;

	for each (auto gameObject in this->objects)
	{
		if (!gameObject->getVectorPending().empty()) {
			tempVector.push_back(gameObject->getVectorPending());

			gameObject->clearPending();
		}
	}

	for each (auto var in tempVector)
	{
		this->addVectorGameObject(var);
		CheckerCollision::addObjects(var);
	}
}

void Layer::addVectorGameObject(std::vector<GameObject*> vector) {
	for each (auto var in vector)
	{
		this->addGameObject(var);
	}
}