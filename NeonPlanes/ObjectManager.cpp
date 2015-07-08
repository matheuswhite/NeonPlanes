#include "ObjectManager.h"

std::vector<GameObject*> ObjectManager::inactivesObjects;

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

void ObjectManager::addInactiveObjects(std::vector<GameObject*> objects) {
	inactivesObjects.insert(inactivesObjects.end(), objects.begin(), objects.end());
}

void ObjectManager::deleteInactivesObjects() {
	for (size_t i = 0; i < inactivesObjects.size(); i++)
	{
		auto it = std::find(inactivesObjects.begin(), inactivesObjects.end(), inactivesObjects.at(i));
		if (it != inactivesObjects.end()) {
			auto obj = inactivesObjects.at(i);
			inactivesObjects.erase(it);
			delete obj;
		}
	}
}
