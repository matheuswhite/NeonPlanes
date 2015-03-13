#pragma once

#include "core.h"

class Command
{
public:
	Command();
	virtual ~Command();
	
	static void shoot();
	static void useLightWall();
	static void moveUp();
	static void moveDown();
	static void moveLeft();
	static void moveRight();
};