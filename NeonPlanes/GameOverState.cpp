#include "GameOverState.h"

GameOverState::GameOverState()
{
	this->addLayer(new Layer("Background"));
	this->addLayer(new Layer("Interaction"));
#if _DEBUG
	this->addLayer(new Layer("Debug"));
#endif

	int posx = 20;

	this->getLayer("Background")->addGameObject(new Background("Background"));

	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(65, 40), Vector2D(300, 80), "GameOver", 74, FONT_PATH + "distortion_of_the_brain_and_mind.ttf", utility::RED, "GameOver"));
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(120, 240), Vector2D(170, 40), "Pontuação", 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Pontuação"));
	
	this->getLayer("Interaction")->addGameObject(new DynamicTextItem(Vector2D(posx, 300), Vector2D(110, 40), "025.0M", 60, FONT_PATH + "Aero.ttf", utility::WHITE, "Distancia"));
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(posx + 105, 300), Vector2D(40, 40), " * ", 60, FONT_PATH + "Aero.ttf", utility::WHITE, "Star"));
	this->getLayer("Interaction")->addGameObject(new DynamicTextItem(Vector2D(posx + 140, 300), Vector2D(90, 40), "10.0", 60, FONT_PATH + "Aero.ttf", utility::WHITE, "Nivel"));
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(posx + 225, 300), Vector2D(40, 40), " = ", 60, FONT_PATH + "Aero.ttf", utility::WHITE, "Equal"));
	this->getLayer("Interaction")->addGameObject(new DynamicTextItem(Vector2D(posx + 260, 300), Vector2D(110, 40), "250.0M", 60, FONT_PATH + "Aero.ttf", utility::WHITE, "Total"));
#if _DEBUG
	this->getLayer("Debug")->addGameObject(new FPS_HUD("FPS_HUD"));
#endif
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(28, 550), Vector2D(370, 23), "<Pressione ENTER ou START para sair>", 60, FONT_PATH + "Aero.ttf", utility::WHITE, "Info"));
}

GameOverState::~GameOverState()
{
}

void GameOverState::execute_BTN_SPACE() {
	Command::doNothing();
}
void GameOverState::execute_BTN_Z() {
	Command::doNothing();
}
void GameOverState::execute_BTN_ENTER() {
	Command::select(utility::MAIN_MENU);
}
void GameOverState::execute_LEFT() {
	Command::doNothing();
}
void GameOverState::execute_RIGHT() {
	Command::doNothing();
}
void GameOverState::execute_UP() {
	Command::doNothing();
}
void GameOverState::execute_DOWN() {
	Command::doNothing();
}

void GameOverState::updateValues(std::string level, std::string distance, std::string total) {
	((DynamicTextItem*)this->getLayer("Interaction")->getGameObject("Distancia"))->updateValue(distance);
	((DynamicTextItem*)this->getLayer("Interaction")->getGameObject("Nivel"))->updateValue(level);
	((DynamicTextItem*)this->getLayer("Interaction")->getGameObject("Total"))->updateValue(total);
}
