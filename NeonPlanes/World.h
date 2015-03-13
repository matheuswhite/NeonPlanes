#pragma once

#include "GameStateHeaders.h"
#include "PackageHeaders.h"
#include "GameObject.h"

class World
{
public:
	World();
	virtual ~World();
	
	static GameState* getCurrentState();
	static Package* getCurrentPackage();

	static void switchGameState(GameState* state);
	static void switchPackage(std::string package);

	static void addPackage(Package* package);
	static Package* getPackage(std::string package);
private:
	static GameState* currentState;
	static Package* currentPackage;

	static std::map< std::string, Package* > map_package;
};
