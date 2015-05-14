#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
	this->addLayer(new Layer("Background"));
	this->addLayer(new Layer("Interaction"));
	this->addLayer(new Layer("Debug"));

	std::vector<HighlightItem*> itens;

	int posx = 75;
	int posy = 340;

	itens.push_back(new HighlightItem("Novo Jogo", new Rectangle(Vector2D(posx, posy), Vector2D(280, 50), "destiny"), new Font("Novo Jogo", FONT_PATH + "Aero.ttf", 54, utility::WHITE), utility::INTER_BLUE, utility::PLAY));
	itens.push_back(new HighlightItem("Highscore", new Rectangle(Vector2D(posx-10, posy + 60), Vector2D(280, 50), "destiny"), new Font("Highscore", FONT_PATH + "Aero.ttf", 54, utility::WHITE), utility::INTER_BLUE, utility::HIGHSCORE));
	itens.push_back(new HighlightItem("Sair", new Rectangle(Vector2D(posx-20, posy + 120), Vector2D(130, 50), "destiny"), new Font("Sair", FONT_PATH + "Aero.ttf", 54, utility::WHITE), utility::INTER_BLUE, utility::SAIR));

	this->getLayer("Background")->addGameObject(std::make_shared<GameObject>(Background("Background")));
	this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(Menu("MainMenu", itens)));
	this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(TitleText("NeonPlanes")));
	this->getLayer("Debug")->addGameObject(std::make_shared<GameObject>(FPS_HUD("FPS_HUD")));
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::execute_BTN_SPACE() {
	auto it = this->getLayer("Interaction")->getGameObject("MainMenu").lock();
	if (it) {
		auto state = ((Menu*)it.get())->getCurrentHighLightItem()->getNextState();
		Command::select(state);
	}
}
void MainMenuState::execute_BTN_Z() {
	Command::doNothing();
}
void MainMenuState::execute_BTN_ENTER() {
	auto it = this->getLayer("Interaction")->getGameObject("MainMenu").lock();
	if (it) {
		auto state = ((Menu*)it.get())->getCurrentHighLightItem()->getNextState();
		Command::select(state);
	}
}
void MainMenuState::execute_LEFT() {
	Command::doNothing();
}
void MainMenuState::execute_RIGHT() {
	Command::doNothing();
}
void MainMenuState::execute_UP() {
	Command::moveMenuUp(this->getLayer("Interaction")->getGameObject("MainMenu"));
}
void MainMenuState::execute_DOWN() {
	Command::moveMenuDown(this->getLayer("Interaction")->getGameObject("MainMenu"));
}
