#include "Layer.h"


Layer::Layer(std::string name)
{
	this->name = name;
}

Layer::~Layer()
{
	for each (auto obj in this->objects)
	{
		delete obj;
	}

	this->objects.clear();
	this->map_objects.clear();
	this->name.clear();
}

void Layer::addGameObject(GameObject* obj) 
{
	this->map_objects.insert(std::pair<std::string, GameObject*>(typeid(*obj).name(), obj));
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