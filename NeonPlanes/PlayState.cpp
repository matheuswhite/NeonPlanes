#include "PlayState.h"

PlayState::PlayState()
{
	this->gameWorldCreated = false;

	this->addLayer(new Layer("Background"));
	this->addLayer(new Layer("Interaction"));
	this->addLayer(new Layer("HUD"));
	this->addLayer(new Layer("Debug"));
}

PlayState::~PlayState()
{
}

void PlayState::createGameWorld() {
	if (!this->gameWorldCreated) {
		
		this->getLayer("Background")->addGameObject(std::make_shared<GameObject>(Background("Background")));
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(Player("Player")));
		/*this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(BlueEnemy("BlueEnemy")));
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(RedEnemy("RedEnemy")));
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(YellowEnemy("YellowEnemy")));
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(BlueProjectile("BlueProjectile")));
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(RedProjectile("RedProjectile")));
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(YellowProjectile("YellowProjectile")));*/
		//this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(WhiteProjectile("WhiteProjectile")));
		this->getLayer("Debug")->addGameObject(std::make_shared<GameObject>(FPS_HUD("FPS_HUD")));
		
		this->gameWorldCreated = true;
	}
}

void PlayState::execute_BTN_SPACE() {
	Command::shoot(this->getLayer("Interaction")->getGameObject("Player"));
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
