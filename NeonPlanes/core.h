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
#include <lua.hpp>
#include <string>
#include <queue>
#include <fstream>
#include <math.h>
#include <stdexcept>
#include <map>
#include <set>
#include <typeinfo>
#include <cmath>

namespace utility {
	enum objectPosition {
		DEFAULT = -1,
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	enum streamMode {
		NORMAL,
		BINARY,
		FORCED
	};

	const std::string SCRIPT_PATH = "..\\Debug\\Scripts\\";
	const std::string IMAGE_PATH = "..\\Debug\\Images\\";
	const std::string CONFIGURATION_PATH = "..\\Debug\\Configurations\\";

	typedef void(*Callback)(void);
}