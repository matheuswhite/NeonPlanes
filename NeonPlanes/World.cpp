#include "World.h"

GameState* World::currentState = nullptr;
Package* World::currentPackage = nullptr;
std::map< std::string, Package* > World::map_package = {};

World::World()
{
	this->addPackage(new MainMenuPackage());
	this->addPackage(new PlayPackage());
	this->addPackage(new MenuPackage());
	this->addPackage(new PausePackage());
}

World::~World()
{
	delete this->currentPackage;
	delete this->currentState;
	this->currentPackage = nullptr;
	this->currentState = nullptr;

	for (std::map<std::string, Package*>::iterator it = this->map_package.begin(); it != this->map_package.end(); ++it) {
		delete it->second;
		it->second = nullptr;
	}

	this->map_package.clear();
}

GameState* World::getCurrentState() {
	return currentState;
}

Package* World::getCurrentPackage() {
	return currentPackage;
}

void World::switchGameState(GameState* state) {
	if (currentState != nullptr) {
		delete currentState;
		currentState = nullptr;
	}
	currentState = state;
}

void World::switchPackage(std::string package) {
	auto temp = map_package[package];
	currentPackage = temp;
}

void World::addPackage(Package* package) {
	map_package.insert(std::pair< std::string, Package* >(typeid(*package).name(), package));
}

Package* World::getPackage(std::string package) {
	return map_package[package];
}