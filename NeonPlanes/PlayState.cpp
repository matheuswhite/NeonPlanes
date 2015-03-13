#include "PlayState.h"

PlayState::PlayState()
{
}

PlayState::~PlayState()
{
}

void PlayState::execute_A() {
	Command::Instance()->action();
}
void PlayState::execute_X() {
	Command::Instance()->UseSkill();
}
void PlayState::execute_B() {
	Command::Instance()->doNothing();
}
void PlayState::execute_RB() {
	Command::Instance()->switchRightSkill();
}
void PlayState::execute_LB() {
	Command::Instance()->switchLeftSkill();
}
void PlayState::execute_START() {
	Command::Instance()->pauseGame();
}
void PlayState::execute_BACK() {
	Command::Instance()->showMenu();
}
void PlayState::execute_LEFT() {
	Command::Instance()->walkLeft();
}
void PlayState::execute_RIGHT() {
	Command::Instance()->walkRight();
}
void PlayState::execute_UP() {
	Command::Instance()->walkUp();
}
void PlayState::execute_DOWN() {
	Command::Instance()->walkDown();
}
