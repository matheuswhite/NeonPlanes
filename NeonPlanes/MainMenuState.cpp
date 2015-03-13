#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::execute_A() {
	Command::Instance()->actionMenu();
}
void MainMenuState::execute_X() {
	Command::Instance()->doNothing();
}
void MainMenuState::execute_B() {
	Command::Instance()->doNothing();
}
void MainMenuState::execute_RB() {
	Command::Instance()->doNothing();
}
void MainMenuState::execute_LB() {
	Command::Instance()->doNothing();
}
void MainMenuState::execute_START() {
	Command::Instance()->actionMenu();
}
void MainMenuState::execute_BACK() {
	Command::Instance()->doNothing();
}
void MainMenuState::execute_LEFT() {
	Command::Instance()->doNothing();
}
void MainMenuState::execute_RIGHT() {
	Command::Instance()->doNothing();
}
void MainMenuState::execute_UP() {
	Command::Instance()->moveMenuUp();
}
void MainMenuState::execute_DOWN() {
	Command::Instance()->moveMenuDown();
}
