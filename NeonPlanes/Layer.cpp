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
	if (this->map_objects.find(obj) != this->map_objects.end()) {
		return this->map_objects.at(obj);
	}
	return nullptr;
}

std::vector<GameObject*> Layer::getGameObjects()
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

void Layer::removeMultiple(std::vector<GameObject*> objects) {
	std::vector<int> indexs;
	std::vector<std::string> names;
	int k = 0;

	for (int i = 0; i < this->objects.size(); i++)
	{
		for (int j = 0; j < objects.size(); j++)
		{
			if (this->objects.at(i) == objects.at(j)) {
				indexs.push_back(i);
				names.push_back(this->objects.at(i)->getName());
			}
		}
	}

	std::sort(indexs.begin(), indexs.end());

	for each (auto var in indexs)
	{
		this->objects.erase(std::remove(this->objects.begin(), this->objects.end(), this->objects.at(var - k)), this->objects.end());
		k++;
	}

	for each (auto var2 in names)
	{
		this->map_objects.erase(var2);
	}
}