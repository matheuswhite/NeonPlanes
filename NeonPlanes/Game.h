#pragma once

#include "core.h"
#include "World.h"
#include "Sprite.h"
#include "Behavior.h"

class Game
{
public:
	Game(std::string name, int windows_x, int windows_y, int flag);
	virtual ~Game();

	bool initialize();
	void draw();
	void update();
	bool handlingEvents();
	void clear();

	bool isInitialize() const;
	SDL_Window* getWindow();
	static SDL_Renderer* getRenderer();
	static World* getWorld();
private:
	SDL_Window* window;
	bool init;
	static SDL_Renderer* renderer;
	static World* world;
};
