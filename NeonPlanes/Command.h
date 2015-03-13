#pragma once

#include "core.h"
#include "Singleton.h"

class Command : public Singleton<Command>
{
public:
	Command();
	virtual ~Command();
	
	void action();
	void doNothing();
	void UseSkill();
	void switchLeftSkill();
	void switchRightSkill();
	void walkUp();
	void walkDown();
	void walkLeft();
	void walkRight();
	void pauseGame();
	void showMenu();
	void resumeGame();
	void moveMenuUp();
	void moveMenuDown();
	void actionMenu();
	void switchTabLeft();
	void switchTabRight();
	void stopPointer();
	void exitLockpick();
};