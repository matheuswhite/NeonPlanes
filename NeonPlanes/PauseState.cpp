#include "PauseState.h"

PauseState::PauseState()
{
	this->addLayer(new Layer("Background"));
	this->addLayer(new Layer("Interaction"));
	this->addLayer(new Layer("Debug"));

	std::vector<HighlightItem*> itens;

	int posx = 75;
	int posy = 270;

	itens.push_back(new HighlightItem("Continuar", new Rectangle(Vector2D(posx, posy), Vector2D(280, 50), "destiny"), new Font("Continuar", FONT_PATH + "Aero.ttf", 54, utility::WHITE), utility::INTER_BLUE, utility::PLAY));
	itens.push_back(new HighlightItem("MainMenu", new Rectangle(Vector2D(posx - 10, posy + 60), Vector2D(130, 50), "destiny"), new Font("Menu Principal", FONT_PATH + "Aero.ttf", 54, utility::WHITE), utility::INTER_BLUE, utility::MAIN_MENU));

	std::cout << "size: " << itens.size() << std::endl;

	this->getLayer("Background")->addGameObject(std::make_shared<GameObject>(Background("Background")));
	this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(Menu("Paused", itens)));
	this->getLayer("Interaction")->addGameObject(std::make_shared<GameObject>(TextItem(Vector2D(65, 40), Vector2D(300, 80), "Pausado", 54, FONT_PATH + "distortion_of_the_brain_and_mind.ttf", utility::GREEN, "Title")));
	this->getLayer("Debug")->addGameObject(std::make_shared<GameObject>(FPS_HUD("FPS_HUD")));
}

PauseState::~PauseState()
{
}

void PauseState::execute_BTN_SPACE() {
	auto it = this->getLayer("Interaction")->getGameObject("Paused").lock();
	if (it) {
		auto state = ((Menu*)it.get())->getCurrentHighLightItem()->getNextState();
		Command::select(state);
	}
}
void PauseState::execute_BTN_Z() {
	Command::doNothing();
}
void PauseState::execute_BTN_ENTER() {
	Command::resume();
}
void PauseState::execute_LEFT() {
	Command::doNothing();
}
void PauseState::execute_RIGHT() {
	Command::doNothing();
}
void PauseState::execute_UP() {
	Command::moveMenuUp(this->getLayer("Interaction")->getGameObject("Paused"));
}
void PauseState::execute_DOWN() {
	Command::moveMenuDown(this->getLayer("Interaction")->getGameObject("Paused"));
}
