#include "PlayState.h"

PlayState::PlayState()
{
	this->gameWorldCreated = false;
}

PlayState::~PlayState()
{
}

void PlayState::createGameWorld() {
	if (!this->gameWorldCreated) {
		this->addLayer(new Layer("Background"));
		this->addLayer(new Layer("Interaction"));
		this->addLayer(new Layer("HUD"));
		this->addLayer(new Layer("Debug"));

#if _DEBUG
		this->getLayer("Debug")->addGameObject(new FPS_HUD(1));
#endif // !_DEBUG
		
		this->gameWorldCreated = true;
	}
}

void PlayState::execute_BTN_SPACE() {
	Command::shoot();
}
void PlayState::execute_BTN_Z() {
	Command::useLightWall();
}
void PlayState::execute_BTN_ENTER() {
	Command::pause();
}
void PlayState::execute_LEFT() {
	Command::moveLeft();
}
void PlayState::execute_RIGHT() {
	Command::moveRight();
}
void PlayState::execute_UP() {
	Command::moveUp();
}
void PlayState::execute_DOWN() {
	Command::moveDown();
}
