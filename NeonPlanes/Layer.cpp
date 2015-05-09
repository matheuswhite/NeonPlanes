#include "Layer.h"


Layer::Layer(std::string name)
{
	this->name = name;
}

Layer::~Layer()
{
}

void Layer::addGameObject(std::shared_ptr<GameObject> obj) 
{
	this->map_objects.insert(std::pair<std::string, std::shared_ptr<GameObject> >(obj->getName(), obj));
	this->objects.push_back(obj);
}

std::weak_ptr<GameObject> Layer::getGameObject(std::string obj) const 
{ 
	return this->map_objects.at(obj); 
}

std::vector<std::shared_ptr<GameObject> > Layer::getGameObjects() const 
{ 
	return this->objects; 
}

std::string Layer::getName() const {
	return this->name;
}

void Layer::addPending() {
	std::vector< std::vector< std::shared_ptr<GameObject> > > tempVector;

	for each (std::weak_ptr<GameObject> i in this->objects)
	{
		auto gameObject = i.lock();
		if (gameObject) {
			if (!gameObject.get()->getVectorPending().empty()) {
				tempVector.push_back(gameObject.get()->getVectorPending());

				gameObject->clearPending();
			}
		}
	}

	for each (auto var in tempVector)
	{
		this->addVectorGameObject(var);
	}
}

void Layer::addVectorGameObject(std::vector<std::shared_ptr<GameObject> > vector) {
	for each (auto var in vector)
	{
		this->addGameObject(var);
	}
}