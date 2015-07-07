#include "PlayState.h"

PlayState::PlayState()
{
	this->gameWorldCreated = false;

	this->addLayer(new Layer("Background"));
	this->addLayer(new Layer("EnemyAI"));
	this->addLayer(new Layer("Interaction"));
	this->addLayer(new Layer("HUD"));
#if _DEBUG
	this->addLayer(new Layer("Debug"));
#endif

	this->createGameWorld();
}

PlayState::~PlayState()
{
}

LevelManager* PlayState::getLevelManager() const {
	return this->level;
}

void PlayState::createGameWorld() {
	if (!this->gameWorldCreated) {
		
		this->getLayer("Background")->addGameObject(new Background("Background"));
		
#if _DEBUG
		this->getLayer("Debug")->addGameObject(new FPS_HUD("FPS_HUD"));
#endif

		this->level = new LevelManager(&this->map_layers);

		this->gameWorldCreated = true;
	}
}

void PlayState::destroyGameWorld() {
	ObjectManager::addInactiveObjects(this->getLayer("Interaction")->getGameObjects());
	ObjectManager::addInactiveObjects(this->getLayer("EnemyAI")->getGameObjects());

	this->getLayer("EnemyAI")->removeMultiple(this->getLayer("EnemyAI")->getGameObjects());
	this->getLayer("Interaction")->removeMultiple(this->getLayer("Interaction")->getGameObjects());

	CheckerCollision::clearObjects();

	this->level->clearObjects();

	ObjectManager::deleteInactivesObjects();

	this->gameWorldCreated = false;
}

void PlayState::runLevelLogic() {
	this->level->levelLogic();
}

void PlayState::execute_BTN_SPACE() {
	if ((Player*)this->getLayer("Interaction")->getGameObject("Player") != nullptr) {
		if ((Player*)this->getLayer("Interaction")->getGameObject("Player")->isActive()) {
			Command::shoot((Player*)this->getLayer("Interaction")->getGameObject("Player"));
		}
	}
}

void PlayState::execute_BTN_Z() {
	if ((Player*)this->getLayer("Interaction")->getGameObject("Player") != nullptr) {
		if ((Player*)this->getLayer("Interaction")->getGameObject("Player")->isActive()) {
			Command::useLightWall((Player*)this->getLayer("Interaction")->getGameObject("Player"));
		}
	}
}
void PlayState::execute_BTN_ENTER() {
	Command::pause();
}
void PlayState::execute_LEFT() {
	if ((Player*)this->getLayer("Interaction")->getGameObject("Player") != nullptr) {
		if ((Player*)this->getLayer("Interaction")->getGameObject("Player")->isActive()) {
			Command::moveLeft((Player*)this->getLayer("Interaction")->getGameObject("Player"));
		}
	}
}
void PlayState::execute_RIGHT() {
	if ((Player*)this->getLayer("Interaction")->getGameObject("Player") != nullptr) {
		if ((Player*)this->getLayer("Interaction")->getGameObject("Player")->isActive()) {
			Command::moveRight((Player*)this->getLayer("Interaction")->getGameObject("Player"));
		}
	}
}
void PlayState::execute_UP() {
	if ((Player*)this->getLayer("Interaction")->getGameObject("Player") != nullptr) {
		if ((Player*)this->getLayer("Interaction")->getGameObject("Player")->isActive()) {
			Command::moveUp((Player*)this->getLayer("Interaction")->getGameObject("Player"));
		}
	}
}
void PlayState::execute_DOWN() {
	if ((Player*)this->getLayer("Interaction")->getGameObject("Player") != nullptr) {
		if ((Player*)this->getLayer("Interaction")->getGameObject("Player")->isActive()) {
			Command::moveDown((Player*)this->getLayer("Interaction")->getGameObject("Player"));
		}
	}
}

void PlayState::stop(bool direction) {
	if ((Player*)this->getLayer("Interaction")->getGameObject("Player") != nullptr) {
		if ((Player*)this->getLayer("Interaction")->getGameObject("Player")->isActive()) {
			Command::stop((Player*)this->getLayer("Interaction")->getGameObject("Player"), direction);
		}
	}
}

void PlayState::totalStop() {
	if ((Player*)this->getLayer("Interaction")->getGameObject("Player") != nullptr) {
		if ((Player*)this->getLayer("Interaction")->getGameObject("Player")->isActive()) {
			Command::totalStop((Player*)this->getLayer("Interaction")->getGameObject("Player"));
		}
	}
}