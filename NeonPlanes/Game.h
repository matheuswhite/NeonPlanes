#pragma once

#include "core.h"
#include "World.h"
#include "SystemsHeaders.h"
#include "GameStateHeaders.h"

#ifndef GAME_FPS
#define GAME_FPS 1000/60
#endif // !GAME_FPS

#ifndef GAME_PAIR
#define GAME_PAIR std::pair<std::string, System*>
#endif // !GAME_PAIR

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

	static SDL_Window* getWindow();
	static SDL_Renderer* getRenderer();
	static World* getWorld();

	static std::vector<System*> getListSystems();
	static System* getSystem(std::string system);

	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;
private:
	bool addSystem(System* system);

	static SDL_Window* window;
	static SDL_Renderer* renderer;
	static World* world;

	static std::vector<System*> systems;
	static std::map<std::string, System*> map_systems;
};
