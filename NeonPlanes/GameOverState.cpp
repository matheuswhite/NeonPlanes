#include "GameOverState.h"

GameOverState::GameOverState()
{
	this->addLayer(new Layer("Background"));
	this->addLayer(new Layer("Interaction"));
#if _DEBUG
	this->addLayer(new Layer("Debug"));
#endif

	auto pair = this->getDistance_Level();
	
	float valS = pair.second / 10;
	int unitS = (int)pair.second % 10;
	int restS = pair.second / 10;
	
	int restT = 0;
	int unitT = 0;
	char modT = ' ';

	int restF = 0;
	int unitF = 0;
	char modF = ' ';

	formatBigValue(pair.first, &unitF, &restF, &modF);
	formatBigValue(pair.first * valS, &unitT, &restT, &modT);

	int posx = 70;

	this->getLayer("Background")->addGameObject(new Background("Background"));
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(65, 40), Vector2D(300, 80), "GameOver", 74, FONT_PATH + "distortion_of_the_brain_and_mind.ttf", utility::RED, "GameOver"));
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(120, 240), Vector2D(170, 40), "Pontuação", 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Pontuação"));
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(posx, 300), Vector2D(90, 40), std::to_string(restF) + "." + std::to_string(unitF) + modF + " * ", 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Distancia"));
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(posx + 85, 300), Vector2D(90, 40), std::to_string(restS) + "." + std::to_string(unitS) + " = ", 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Nivel"));
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(posx + 175, 300), Vector2D(90, 40), std::to_string(restT) + "." + std::to_string(unitT) + modT, 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Total"));
#if _DEBUG
	this->getLayer("Debug")->addGameObject(new FPS_HUD("FPS_HUD"));
#endif
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(28, 550), Vector2D(370, 23), "<Pressione ENTER ou START para sair>", 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Info"));
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

std::pair<int, float> GameOverState::getDistance_Level() {

	return std::pair<int, float>(13000, 13);
}

void GameOverState::formatBigValue(float val, int* unit, int* rest, char* mod) {
	if (val > 1000000000000) {
		*rest = val / 1000000000000;
		*unit = (int)val % 1000000000000;
		*unit /= 100000000000;
		*mod = 'T';
	}
	else if (val > 1000000000) {
		*rest = val / 1000000000;
		*unit = (int)val % 1000000000;
		*unit /= 100000000;
		*mod = 'G';
	}
	else if (val > 1000000) {
		*rest = val / 1000000;
		*unit = (int)val % 1000000;
		*unit /= 100000;
		*mod = 'M';
	}
	else if (val > 1000) {
		*rest = val / 1000;
		*unit = (int)val % 1000;
		*unit /= 100;
		*mod = 'K';
	}
	std::cout << std::endl;
}