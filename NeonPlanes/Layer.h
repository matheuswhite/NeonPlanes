#pragma once

#include "GameObject.h"

class Layer
{
public:
	Layer(std::string name);
	virtual ~Layer();

	void addGameObject(std::shared_ptr<GameObject> obj);
	void addVectorGameObject(std::vector<std::shared_ptr<GameObject> > vector);
	std::weak_ptr<GameObject> getGameObject(std::string obj) const;
	std::vector< std::shared_ptr<GameObject> > getGameObjects() const;
	std::string getName() const;
	void addPending();
	
private:
	std::string name;
	std::vector< std::shared_ptr<GameObject> > objects;
	std::map< std::string, std::weak_ptr<GameObject> > map_objects;
};
