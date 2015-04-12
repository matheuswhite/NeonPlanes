#pragma once

#include "Sprite.h"
#include "Behavior.h"

class GameObject {
public:
	GameObject(Uint32 id);
	virtual ~GameObject();
	
	bool hasComponent(std::string component) const;
	bool hasSprite(std::string sprite) const;
	bool hasBehavior(std::string behavior) const;

	void addComponent(Component* component);
	void addSprite(Sprite* sprite);
	void addBehavior(Behavior* behavior);

	Uint32 getGameObjectID() const;
	std::vector<Component*> getVectorComponents() const;
	std::vector<Sprite*> getVectorSprites() const;
	std::vector<Behavior*> getVectorBaheviors() const;

	Component* getComponent(std::string component) const;
	Sprite* getSprite(std::string sprite) const;
	Behavior* getBehavior(std::string behavior) const;

	bool isActive() const;

	bool operator==(GameObject* second) const;
protected:
	Uint32 id;
	bool active;

	std::vector<Sprite*> sprites;
	std::vector<Behavior*> behaviors;
	std::vector<Component*> components;

	std::map<std::string, Component*> map_components;
	std::map<std::string, Sprite*> map_sprites;
	std::map<std::string, Behavior*> map_behaviors;
};
