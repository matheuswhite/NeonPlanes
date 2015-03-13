#include "PauseState.h"


PauseState::PauseState()
{
}


PauseState::~PauseState()
{
}

void PauseState::execute_A() {
	Command::Instance()->actionMenu();
}
void PauseState::execute_X() {
	Command::Instance()->doNothing();
}
void PauseState::execute_B() {
	Command::Instance()->resumeGame();
}
void PauseState::execute_RB() {
	Command::Instance()->doNothing();
}
void PauseState::execute_LB() {
	Command::Instance()->doNothing();
}
void PauseState::execute_START() {
	Command::Instance()->resumeGame();
}
void PauseState::execute_BACK() {
	Command::Instance()->showMenu();
}
void PauseState::execute_LEFT() {
	Command::Instance()->doNothing();
}
void PauseState::execute_RIGHT() {
	Command::Instance()->doNothing();
}
void PauseState::execute_UP() {
	Command::Instance()->moveMenuUp();
}
void PauseState::execute_DOWN() {
	Command::Instance()->moveMenuDown();
}
