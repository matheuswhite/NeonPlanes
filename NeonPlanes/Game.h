#pragma once

#include "core.h"
#include "World.h"
#include "GameStateHeaders.h"
#include "ToolHeaders.h"
#include "ComponentHeaders.h"

class Game
{
public:
	Game(std::string name, int windows_x, int windows_y, int flag);
	virtual ~Game();

	void init();
	void draw();
	void update();
	bool handlingEvents();
	void clear();

	SDL_Window* getWindow();
	static SDL_Renderer* getRenderer();
	static World* getWorld();
private:
	SDL_Window* window;
	static SDL_Renderer* renderer;
	static World* world;
};
