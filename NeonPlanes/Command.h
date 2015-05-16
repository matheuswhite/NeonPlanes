#pragma once

#include "core.h"
#include "Player.h"
#include "Notifier.h"
#include "Menu.h"

class Command
{
public:
	Command();
	virtual ~Command();
	
	static void shoot(Player* player);
	static void useLightWall(Player* player);
	static void pause();
	static void moveUp();
	static void moveDown();
	static void moveLeft();
	static void moveRight();
	static void stop();

	static void select(Uint8 nextState);
	static void resume();
	static void moveMenuUp(Menu* menu);
	static void moveMenuDown(Menu* menu);

	static void doNothing();
};