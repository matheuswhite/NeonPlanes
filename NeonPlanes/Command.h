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
	
	static void shoot(std::weak_ptr<GameObject> player);
	static void useLightWall();
	static void pause();
	static void moveUp();
	static void moveDown();
	static void moveLeft();
	static void moveRight();
	static void stop();

	static void select(Uint8 nextState);
	static void resume();
	static void moveMenuUp(std::weak_ptr<GameObject> menu);
	static void moveMenuDown(std::weak_ptr<GameObject> menu);

	static void doNothing();
};