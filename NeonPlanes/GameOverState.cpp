#include "GameOverState.h"

GameOverState::GameOverState()
{
}

GameOverState::~GameOverState()
{
}

void GameOverState::execute_BTN_SPACE() {
	Command::select();
}
void GameOverState::execute_BTN_Z() {
	Command::doNothing();
}
void GameOverState::execute_BTN_ENTER() {
	Command::select();
}
void GameOverState::execute_LEFT() {
	Command::doNothing();
}
void GameOverState::execute_RIGHT() {
	Command::doNothing();
}
void GameOverState::execute_UP() {
	Command::moveMenuUp();
}
void GameOverState::execute_DOWN() {
	Command::moveMenuDown();
}
