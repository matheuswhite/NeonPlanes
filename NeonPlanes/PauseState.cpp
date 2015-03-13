#include "PauseState.h"


PauseState::PauseState()
{
}


PauseState::~PauseState()
{
}

void PauseState::execute_BTN_SPACE() {
	Command::select();
}
void PauseState::execute_BTN_Z() {
	Command::doNothing();
}
void PauseState::execute_BTN_ENTER() {
	Command::resume();
}
void PauseState::execute_LEFT() {
	Command::doNothing();
}
void PauseState::execute_RIGHT() {
	Command::doNothing();
}
void PauseState::execute_UP() {
	Command::moveMenuUp();
}
void PauseState::execute_DOWN() {
	Command::moveMenuDown();
}
