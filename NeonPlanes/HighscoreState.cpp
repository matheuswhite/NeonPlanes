#include "HighscoreState.h"

HighscoreState::HighscoreState()
{
	this->addLayer(new Layer("Background"));
	this->addLayer(new Layer("Interaction"));
#if _DEBUG
	this->addLayer(new Layer("Debug"));
#endif

	auto vector_pair = this->getHighscore();

	int posx = 40;
	int posx2 = 300;

	int posy = 180;

	this->getLayer("Background")->addGameObject(new Background("Background"));
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(65, 40), Vector2D(300, 80), "Highscore", 74, FONT_PATH + "distortion_of_the_brain_and_mind.ttf", utility::YELLOW, "Highscore"));

	this->getLayer("Interaction")->addGameObject(new DynamicTextItem(Vector2D(posx, posy), Vector2D(90, 40), vector_pair.at(0).first, 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Nome0"));
	this->getLayer("Interaction")->addGameObject(new DynamicTextItem(Vector2D(posx2, posy), Vector2D(90, 40), vector_pair.at(0).second, 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Valor0"));

	this->getLayer("Interaction")->addGameObject(new DynamicTextItem(Vector2D(posx, posy + 50), Vector2D(90, 40), vector_pair.at(1).first, 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Nome1"));
	this->getLayer("Interaction")->addGameObject(new DynamicTextItem(Vector2D(posx2, posy + 50), Vector2D(90, 40), vector_pair.at(1).second, 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Valor1"));
	
	this->getLayer("Interaction")->addGameObject(new DynamicTextItem(Vector2D(posx, posy + 100), Vector2D(90, 40), vector_pair.at(2).first, 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Nome2"));
	this->getLayer("Interaction")->addGameObject(new DynamicTextItem(Vector2D(posx2, posy + 100), Vector2D(90, 40), vector_pair.at(2).second, 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Valor2"));
	
	this->getLayer("Interaction")->addGameObject(new DynamicTextItem(Vector2D(posx, posy + 150), Vector2D(90, 40), vector_pair.at(3).first, 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Nome3"));
	this->getLayer("Interaction")->addGameObject(new DynamicTextItem(Vector2D(posx2, posy + 150), Vector2D(90, 40), vector_pair.at(3).second, 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Valor3"));

	this->getLayer("Interaction")->addGameObject(new DynamicTextItem(Vector2D(posx, posy + 200), Vector2D(90, 40), vector_pair.at(4).first, 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Nome4"));
	this->getLayer("Interaction")->addGameObject(new DynamicTextItem(Vector2D(posx2, posy + 200), Vector2D(90, 40), vector_pair.at(4).second, 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Valor4"));
	
#if _DEBUG
	this->getLayer("Debug")->addGameObject(new FPS_HUD("FPS_HUD"));
#endif
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(28, 550), Vector2D(370, 23), "<Pressione ENTER ou START para sair>", 54, FONT_PATH + "Aero.ttf", utility::WHITE, "Info"));
}

HighscoreState::~HighscoreState()
{
}

void HighscoreState::updateValues() {
	auto vector_pair = this->getHighscore();

	for (size_t i = 0; i < 5; i++)
	{
		((DynamicTextItem*)this->getLayer("Interaction")->getGameObject("Nome" + std::to_string(i)))->updateValue(vector_pair.at(i).first);
		((DynamicTextItem*)this->getLayer("Interaction")->getGameObject("Valor" + std::to_string(i)))->updateValue(vector_pair.at(i).second);
	}
}

std::vector<std::pair<std::string, std::string> > HighscoreState::getHighscore() {
	std::vector<std::pair<std::string, std::string> > vector_pair;
	std::vector<ScoreData*> vector_score;
	std::string filePath = DATA_PATH + "save.gdata";

	if (!DataStore::hasFile(filePath)) {
		ScoreData* score1 = new ScoreData("MT2", 23000000000000);
		ScoreData* score2 = new ScoreData("MK5", 18000000000);
		ScoreData* score3 = new ScoreData("LK1", 11000000);
		ScoreData* score4 = new ScoreData("JN3", 16000);
		ScoreData* score5 = new ScoreData("EPH", 200);

		vector_score.push_back(score1);
		vector_score.push_back(score2);
		vector_score.push_back(score3);
		vector_score.push_back(score4);
		vector_score.push_back(score5);

		DataStore::WriteFile(filePath, vector_score);
	}
		
	vector_score = DataStore::ReadFile(filePath);

	for (size_t i = 0; i < 5; i++)
	{
		std::string valueStr = std::to_string(vector_score.at(i)->unitValue) + "." + std::to_string(vector_score.at(i)->decimalValue) + vector_score.at(i)->modifier;
		vector_pair.push_back(std::pair<std::string, std::string>(vector_score.at(i)->name, valueStr));
	}

	return vector_pair;
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