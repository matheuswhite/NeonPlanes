#pragma once

#include "core.h"

class GameObject;
class World;

class ObjectManager
{
public:
	ObjectManager();
	virtual ~ObjectManager();

	static void addInactiveObjects(std::vector<GameObject*> objects);
	static void deleteInactivesObjects();
private:
	static std::vector<GameObject*> inactivesObjects;
};
