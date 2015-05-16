#pragma once

#include "World.h"
#include "Behavior.h"
#include "Sprite.h"

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
	SDL_Window* getWindow() const;
	static SDL_Renderer* getRenderer();
	static World *getGameWorld();
private:
	bool init;
	static World *gameWorld;
	
	bool shootState;
	bool lightState;
	bool upState;
	bool downState;
	bool leftState;
	bool rightState;
};
