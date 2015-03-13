#pragma once

#include "GameObject.h"

class Layer
{
public:
	Layer();
	virtual ~Layer();

	void addGameObject(GameObject* obj);
	GameObject* getGameObject(std::string obj) const;
	std::vector< GameObject* > getGameObjects() const;
	
private:
	std::vector< GameObject* > objects;
	std::map< std::string, GameObject* > map_objects;
};
