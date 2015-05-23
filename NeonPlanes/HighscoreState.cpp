#include "HighscoreState.h"

HighscoreState::HighscoreState()
{
	this->addLayer(new Layer("Background"));
	this->addLayer(new Layer("Interaction"));
	this->addLayer(new Layer("Debug"));

	auto vector_pair = this->getHighscore();

	int posx = 40;
	int posx2 = 300;

	int posy = 180;

	this->getLayer("Background")->addGameObject(new Background("Background"));
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(65, 40), Vector2D(300, 80), "Highscore", 74, FONT_PATH + "distortion_of_the_brain_and_mind.ttf", utility::YELLOW, "Highscore"));

	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(posx, posy), Vector2D(90, 40), vector_pair.at(0).first, 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Nome1"));
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(posx2, posy), Vector2D(90, 40), vector_pair.at(0).second, 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Valor1"));

	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(posx, posy + 50), Vector2D(90, 40), vector_pair.at(1).first, 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Nome2"));
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(posx2, posy + 50), Vector2D(90, 40), vector_pair.at(1).second, 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Valor2"));
	
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(posx, posy + 100), Vector2D(90, 40), vector_pair.at(2).first, 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Nome3"));
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(posx2, posy + 100), Vector2D(90, 40), vector_pair.at(2).second, 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Valor3"));
	
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(posx, posy + 150), Vector2D(90, 40), vector_pair.at(3).first, 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Nome4"));
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(posx2, posy + 150), Vector2D(90, 40), vector_pair.at(3).second, 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Valor4"));

	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(posx, posy + 200), Vector2D(90, 40), vector_pair.at(4).first, 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Nome5"));
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(posx2, posy + 200), Vector2D(90, 40), vector_pair.at(4).second, 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Valor5"));
	
	this->getLayer("Debug")->addGameObject(new FPS_HUD("FPS_HUD"));
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(28, 550), Vector2D(370, 23), "<Pressione ENTER ou START para sair>", 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Info"));
}

HighscoreState::~HighscoreState()
{
}

std::vector<std::pair<std::string, std::string> > HighscoreState::getHighscore() {
	std::vector<std::pair<std::string, std::string> > vector;

	vector.push_back(std::pair<std::string, std::string>("MAT", "11M"));
	vector.push_back(std::pair<std::string, std::string>("MAC", "7.3M"));
	vector.push_back(std::pair<std::string, std::string>("LUC", "513K"));
	vector.push_back(std::pair<std::string, std::string>("JOE", "316K"));
	vector.push_back(std::pair<std::string, std::string>("PAL", "802"));

	return vector;
}

void HighscoreState::execute_BTN_SPACE() {
	Command::doNothing();
}
void HighscoreState::execute_BTN_Z() {
	Command::doNothing();
}
void HighscoreState::execute_BTN_ENTER() {
	Command::select(utility::MAIN_MENU);
}
void HighscoreState::execute_LEFT() {
	Command::doNothing();
}
void HighscoreState::execute_RIGHT() {
	Command::doNothing();
}
void HighscoreState::execute_UP() {
	Command::doNothing();
}
void HighscoreState::execute_DOWN() {
	Command::doNothing();
}