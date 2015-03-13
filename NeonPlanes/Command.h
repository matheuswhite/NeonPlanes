#pragma once

#include "core.h"

class Command
{
public:
	Command();
	virtual ~Command();
	
	static void shoot();
	static void useLightWall();
	static void pause();
	static void moveUp();
	static void moveDown();
	static void moveLeft();
	static void moveRight();

	static void select();
	static void resume();
	static void moveMenuUp();
	static void moveMenuDown();

	static void doNothing();
};