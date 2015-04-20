#include "GameObject.h"

GameObject::GameObject(Uint32 id) {
	this->id = id;
	this->active = true;
}

GameObject::~GameObject() {}

bool GameObject::hasComponent(std::string component) const {
	if (this->map_components.find(component) != this->map_components.end())
		return true;
	return false;
}

void GameObject::addComponent(Component* component) {
	this->components.push_back(component);
	this->map_components.insert(GAME_OBJECT_PAIR(component->getName() , component));
}

Component* GameObject::getComponent(std::string component) const {
	return this->map_components.at(component);
}

Uint32 GameObject::getGameObjectID() const {
	return this->id;
}

bool GameObject::isActive() const {
	return this->active;
}

bool GameObject::operator==(GameObject* second) const {
	return (this->id == second->id) && (typeid(*this) == typeid(*second));
}

std::vector<Component*> GameObject::getVectorComponents() const {
	return this->components;
}

void GameObject::addSprite(Sprite* sprite) {
	this->sprites.push_back(sprite);
	this->map_sprites.insert(GAME_OBJECT_SPRITE_PAIR(sprite->getName(), sprite));
}

void GameObject::addBehavior(Behavior* behavior) {
	this->behaviors.push_back(behavior);
	this->map_behaviors.insert(GAME_OBJECT_BEHAVIOR_PAIR(behavior->getName(), behavior));
}

std::vector<Behavior*> GameObject::getVectorBaheviors() const {
	return this->behaviors;
}

std::vector<Sprite*> GameObject::getVectorSprites() const {
	return this->sprites;
}

Sprite* GameObject::getSprite(std::string sprite) const {
	return this->map_sprites.at(sprite);
}

Behavior* GameObject::getBehavior(std::string behavior) const {
	return this->map_behaviors.at(behavior);
}

bool GameObject::hasSprite(std::string sprite) const {
	if (this->map_sprites.find(sprite) != this->map_sprites.end())
		return true;
	return false;
}

bool GameObject::hasBehavior(std::string behavior) const {
	if (this->map_behaviors.find(behavior) != this->map_behaviors.end())
		return true;
	return false;
}
