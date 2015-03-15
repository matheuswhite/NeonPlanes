#pragma once

#include "core.h"
#include "ComponentHeaders.h"

class GameObject {
public:
	GameObject(){}
	GameObject(Uint32 id);
	virtual ~GameObject();
	
	bool hasComponent(std::string component) const;
	void addComponent(Component* component);
	Uint32 getGameObjectID() const;
	Component* getComponent(std::string component) const;
	bool isActive() const;

	bool operator==(GameObject* second) const;
protected:
	Uint32 id;
	bool active;

	std::vector<Component*> components;
	std::map<std::string, Component*> map_components;
};
