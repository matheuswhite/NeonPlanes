#pragma once

#include "GameObject.h"

class Layer
{
public:
	Layer(std::string name);
	virtual ~Layer();

	void addGameObject(GameObject* obj);
	GameObject* getGameObject(std::string obj) const;
	std::vector< GameObject* > getGameObjects() const;
	std::string getName() const;
	
private:
	std::string name;
	std::vector< GameObject* > objects;
	std::map< std::string, GameObject* > map_objects;
};
