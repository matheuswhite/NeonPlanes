/*
 * core.h
 *
 *  Created on: 15/01/2015
 *      Author: Matheus
 */
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

#else
//Release Mode

const std::string IMAGE_PATH = "Images\\";

#endif // !_DEBUG

#define GAME_FPS 1000/60
#define SCREEN_WIDTH 420
#define SCREEN_HEIGHT 590
#define GAME_OBJECT_PAIR std::pair<std::string, Component*>

namespace utility {
	enum streamMode {
		NORMAL,
		BINARY,
		FORCED
	};

	const SDL_Color WHITE = { 255, 255, 255 };
	const SDL_Color RED = { 255, 0, 0 };
	const SDL_Color BLUE = { 0, 255, 0 };
	const SDL_Color GREEN = { 0, 0, 255 };
}