#include "GameObject.h"

GameObject::GameObject(Uint32 id) {
	this->id = id;
	this->active = true;
}

GameObject::~GameObject() {
	for each (auto var in this->components)
	{
		delete var;
	}

	this->components.clear();
	this->map_components.clear();
}

bool GameObject::hasComponent(std::string component) const {
	if (this->map_components.find(component) != this->map_components.end())
		return true;
	return false;
}

void GameObject::addComponent(Component* component) {
	this->components.push_back(component);
	this->map_components.insert(GAME_OBJECT_PAIR(typeid(*component).name() , component));
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
