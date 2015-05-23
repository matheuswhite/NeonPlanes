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
	static void moveUp(Player* player);
	static void moveDown(Player* player);
	static void moveLeft(Player* player);
	static void moveRight(Player* player);
	static void stop(Player* player, bool vertical);
	static void totalStop(Player* player);

	static void select(Uint8 nextState);
	static void resume();
	static void moveMenuUp(Menu* menu);
	static void moveMenuDown(Menu* menu);

	static void doNothing();
};