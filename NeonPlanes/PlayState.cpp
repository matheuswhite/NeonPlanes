#include "PlayState.h"

PlayState::PlayState()
{
	this->gameWorldCreated = false;

	this->addLayer(new Layer("Background"));
	this->addLayer(new Layer("EnemyIA"));
	this->addLayer(new Layer("Interaction"));
	this->addLayer(new Layer("HUD"));
	this->addLayer(new Layer("Debug"));
}

PlayState::~PlayState()
{
}

void PlayState::createGameWorld() {
	if (!this->gameWorldCreated) {
		
		this->getLayer("Background")->addGameObject(new Background("Background"));
		this->getLayer("Interaction")->addGameObject(new Player("Player"));
		/*
		new Rectangle(Vector2D(0,610), Vector2D(420,590), "source")
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(BlueEnemy("BlueEnemy")));
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(RedEnemy("RedEnemy")));
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(YellowEnemy("YellowEnemy")));
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(BlueProjectile("BlueProjectile")));
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(RedProjectile("RedProjectile")));
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(YellowProjectile("YellowProjectile")));*/
		this->getLayer("Debug")->addGameObject(new FPS_HUD("FPS_HUD"));
		
		CheckerCollision::addObjects(this->getLayer("Interaction")->getGameObjects());

		CheckerCollision::addAirplanes((Airplane*)this->getLayer("Interaction")->getGameObject("Player"));

		this->gameWorldCreated = true;
	}
}

void PlayState::destroyGameWorld() {

}

void PlayState::execute_BTN_SPACE() {
	Command::shoot((Player*)this->getLayer("Interaction")->getGameObject("Player"));
}
void PlayState::execute_BTN_Z() {
	Command::useLightWall((Player*)this->getLayer("Interaction")->getGameObject("Player"));
}
void PlayState::execute_BTN_ENTER() {
	Command::pause();
}
void PlayState::execute_LEFT() {
	Command::moveLeft((Player*)this->getLayer("Interaction")->getGameObject("Player"));
}
void PlayState::execute_RIGHT() {
	Command::moveRight((Player*)this->getLayer("Interaction")->getGameObject("Player"));
}
void PlayState::execute_UP() {
	Command::moveUp((Player*)this->getLayer("Interaction")->getGameObject("Player"));
}
void PlayState::execute_DOWN() {
	Command::moveDown((Player*)this->getLayer("Interaction")->getGameObject("Player"));
}

void PlayState::stop(bool direction) {
	Command::stop((Player*)this->getLayer("Interaction")->getGameObject("Player"), direction);
}

void PlayState::totalStop() {
	Command::totalStop((Player*)this->getLayer("Interaction")->getGameObject("Player"));
}