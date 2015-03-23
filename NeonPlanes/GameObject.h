#pragma once

#include "Component.h"

class GameObject {
public:
	GameObject(Uint32 id);
	virtual ~GameObject();
	
	bool hasComponent(std::string component) const;
	void addComponent(Component* component);
	Uint32 getGameObjectID() const;
	std::vector<Component*> getVectorComponents() const;
	Component* getComponent(std::string component) const;
	bool isActive() const;

	bool operator==(GameObject* second) const;
protected:
	Uint32 id;
	bool active;

	std::vector<Component*> components;
	std::map<std::string, Component*> map_components;
};
