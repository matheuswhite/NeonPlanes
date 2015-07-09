#pragma once

#include <iostream>
#include <list>
#include <algorithm>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <queue>
#include <fstream>
#include <math.h>
#include <stdexcept>
#include <ctime>
#include <map>
#include <set>
#include <typeinfo>
#include <cmath>
#include <functional>

#if _DEBUG
//Debug Mode

const std::string IMAGE_PATH = "..\\Debug\\Images\\";
const std::string FONT_PATH = "..\\Debug\\Fonts\\";
const std::string DATA_PATH = "..\\Debug\\Data\\";

#else
//Release Mode

const std::string IMAGE_PATH = "Images\\";
const std::string FONT_PATH = "Fonts\\";
const std::string DATA_PATH = "Data\\";

#endif // !_DEBUG

#define GAME_FPS 1000/60
#define SCREEN_WIDTH 420
#define SCREEN_HEIGHT 590
#define TOP_BOUND 85
#define BOTTOM_BOUND (SCREEN_HEIGHT - 61)
#define TOP_ZONE 155
#define BOTTOM_ZONE 380
#define GAME_OBJECT_PAIR std::pair<std::string, Component*>
#define GAME_OBJECT_SPRITE_PAIR std::pair<std::string, Sprite*>
#define GAME_OBJECT_BEHAVIOR_PAIR std::pair<std::string, Behavior*>
#define DEFAULT -1

namespace utility {
	enum streamMode {
		READ,
		WRITE
	};

	enum textureMode {
		IMAGE,
		TEXT
	};

	enum states {
		PLAY,
		MAIN_MENU,
		PAUSE,
		GAMEOVER,
		HIGHSCORE
	};

	enum enemies {
		YELLOW_ENEMY,
		RED_ENEMY,
		BLUE_ENEMY
	};

	enum side
	{
		LEFT,
		RIGHT
	};

	const SDL_Color WHITE = { 255, 255, 255 };
	const SDL_Color RED = { 255, 0, 0 };
	const SDL_Color BLUE = { 0, 0, 255 };
	const SDL_Color GREEN = { 0, 255, 0 };
	const SDL_Color LIGHT_BLUE = { 0, 255, 255 };
	const SDL_Color BLACK = { 0, 0, 0 };
	const SDL_Color YELLOW = { 255, 255, 0 };
	const SDL_Color DARK_MAGENTA = { 139, 0, 139 };
	const SDL_Color INTER_GRAY = { 25, 25, 25 };
	const SDL_Color LEMON = { 253, 233, 16 };
	const SDL_Color AMBER = { 255, 191, 0 };
	const SDL_Color GOLD = { 255, 215, 0 };

	template <class U>
	void remove(std::vector<U>* vector, U object) {
		auto it = std::find(vector->begin(), vector->end(), object);
		if (it != vector->end()) vector->erase(it);
	}

	template <class U>
	void remove(std::vector<U>* vector, int index) {
		try {
			vector->erase(index);
		}
		catch (const std::out_of_range& e) {
			std::cerr << "Out of Range error: " << e.what() << std::endl;

			getchar();
		}
	}
}

extern SDL_Window* window;
extern SDL_Renderer* renderer;