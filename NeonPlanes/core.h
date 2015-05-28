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
#include <map>
#include <set>
#include <typeinfo>
#include <cmath>

#if _DEBUG
//Debug Mode

const std::string IMAGE_PATH = "..\\Debug\\Images\\";
const std::string FONT_PATH = "..\\Debug\\Fonts\\";

#else
//Release Mode

const std::string IMAGE_PATH = "Images\\";
const std::string FONT_PATH = "Fonts\\";

#endif // !_DEBUG

#define GAME_FPS 1000/60
#define SCREEN_WIDTH 420
#define SCREEN_HEIGHT 590
#define GAME_OBJECT_PAIR std::pair<std::string, Component*>
#define GAME_OBJECT_SPRITE_PAIR std::pair<std::string, Sprite*>
#define GAME_OBJECT_BEHAVIOR_PAIR std::pair<std::string, Behavior*>

namespace utility {
	enum streamMode {
		NORMAL,
		BINARY,
		FORCED
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

	const SDL_Color WHITE = { 255, 255, 255 };
	const SDL_Color RED = { 255, 0, 0 };
	const SDL_Color BLUE = { 0, 0, 255 };
	const SDL_Color GREEN = { 0, 255, 0 };
	const SDL_Color LIGHT_BLUE = { 0, 255, 255 };
	const SDL_Color INTER_BLUE = { 0, 0, 205 };
	const SDL_Color YELLOW = { 255, 255, 0 };

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