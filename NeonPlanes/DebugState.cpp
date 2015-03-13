#include "DebugState.h"

DebugState::DebugState()
{
}

DebugState::~DebugState()
{
}

void DebugState::execute_BTN_SPACE() {
	Command::shoot();
}
void DebugState::execute_BTN_Z() {
	Command::useLightWall();
}
void DebugState::execute_BTN_ENTER() {
	Command::pause();
}
void DebugState::execute_LEFT() {
	Command::moveLeft();
}
void DebugState::execute_RIGHT() {
	Command::moveRight();
}
void DebugState::execute_UP() {
	Command::moveUp();
}
void DebugState::execute_DOWN() {
	Command::moveDown();
}
