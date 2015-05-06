#include "PlayState.h"

PlayState::PlayState()
{
	this->gameWorldCreated = false;

	this->addLayer(new Layer("Background"));
	this->addLayer(new Layer("Interaction"));
	this->addLayer(new Layer("HUD"));
#if _DEBUG
	this->addLayer(new Layer("Debug"));
#endif
}

PlayState::~PlayState()
{
}

void PlayState::createGameWorld() {
	if (!this->gameWorldCreated) {
		
		this->getLayer("Background")->addGameObject(std::make_shared<GameObject>(Background(1, "Background")));
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(Player(2, "Player")));
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(BlueEnemy(3, "BlueEnemy")));
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(RedEnemy(4, "RedEnemy")));
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(YellowEnemy(5, "YellowEnemy")));
#if _DEBUG
		this->getLayer("Debug")->addGameObject(std::make_shared<GameObject>(FPS_HUD(3, "FPS_HUD")));
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
