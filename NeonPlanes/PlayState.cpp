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
}

PlayState::~PlayState()
{
}

void PlayState::createGameWorld() {
	if (!this->gameWorldCreated) {
		
		this->getLayer("Background")->addGameObject(new Background("Background"));
		this->getLayer("Interaction")->addGameObject(new Player("Player"));
		this->getLayer("Interaction")->addGameObject(new YellowEnemy("YellowEnemy", new Rectangle(Vector2D(-65, 380), Vector2D(54, 55), "destiny"), 4));
		this->getLayer("Interaction")->addGameObject(new RedEnemy("RedEnemy", new Rectangle(Vector2D(SCREEN_WIDTH + 11, 380), Vector2D(54, 55), "destiny"), -4));
		//this->getLayer("Interaction")->addGameObject(new BlueEnemy("BlueEnemy", new Rectangle(Vector2D(-65, 380), Vector2D(54, 55), "destiny"), 4));
		/*
		new Rectangle(Vector2D(0,610), Vector2D(420,590), "source")
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(BlueEnemy("BlueEnemy")));
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(RedEnemy("RedEnemy")));
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(YellowEnemy("YellowEnemy")));
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(BlueProjectile("BlueProjectile")));
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(RedProjectile("RedProjectile")));
		this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(YellowProjectile("YellowProjectile")));*/
#if _DEBUG
		this->getLayer("Debug")->addGameObject(new FPS_HUD("FPS_HUD"));
#endif
		CheckerCollision::addObjects(this->getLayer("Interaction")->getGameObjects());

		CheckerCollision::addAirplanes((Airplane*)this->getLayer("Interaction")->getGameObject("Player"));
		CheckerCollision::addAirplanes((Airplane*)this->getLayer("Interaction")->getGameObject("YellowEnemy"));
		CheckerCollision::addAirplanes((Airplane*)this->getLayer("Interaction")->getGameObject("RedEnemy"));

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