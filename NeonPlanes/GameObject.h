#pragma once

#include "Sprite.h"
#include "Behavior.h"

class GameObject {
public:
	GameObject(std::string name);
	virtual ~GameObject();
	
	bool hasComponent(std::string component) const;
	bool hasSprite(std::string sprite) const;
	bool hasBehavior(std::string behavior) const;
	void clearPending();

	void addComponent(Component* component);
	void addSprite(Sprite* sprite);
	void addBehavior(Behavior* behavior);
	void addPending(GameObject* obj);

	std::vector<Component*> getVectorComponents() const;
	std::vector<Sprite*> getVectorSprites() const;
	std::vector<Behavior*> getVectorBaheviors() const;
	std::vector<GameObject* > getVectorPending() const;
	
	std::string getName() const;
	Component* getComponent(std::string component) const;
	Sprite* getSprite(std::string sprite) const;
	Behavior* getBehavior(std::string behavior) const;

	bool isActive() const;

	bool operator==(GameObject* second) const;
protected:
	bool active;
	std::string name;

	std::vector<Sprite*> sprites;
	std::vector<Behavior*> behaviors;
	std::vector<Component*> components;

	std::map<std::string, Component*> map_components;
	std::map<std::string, Sprite*> map_sprites;
	std::map<std::string, Behavior*> map_behaviors;

	std::vector<GameObject*> pending;
};
