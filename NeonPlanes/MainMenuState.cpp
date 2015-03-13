#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::execute_BTN_SPACE() {
	Command::select();
}
void MainMenuState::execute_BTN_Z() {
	Command::doNothing();
}
void MainMenuState::execute_BTN_ENTER() {
	Command::select();
}
void MainMenuState::execute_LEFT() {
	Command::doNothing();
}
void MainMenuState::execute_RIGHT() {
	Command::doNothing();
}
void MainMenuState::execute_UP() {
	Command::moveMenuUp();
}
void MainMenuState::execute_DOWN() {
	Command::moveMenuDown();
}
