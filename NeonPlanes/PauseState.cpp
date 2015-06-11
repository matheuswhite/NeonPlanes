#include "PauseState.h"

PauseState::PauseState()
{
	this->addLayer(new Layer("Background"));
	this->addLayer(new Layer("Interaction"));
#if _DEBUG
	this->addLayer(new Layer("Debug"));
#endif
	std::vector<HighlightItem*> itens;

	int posx = 75;
	int posy = 270;

	itens.push_back(new HighlightItem("Continuar", new Rectangle(Vector2D(posx, posy), Vector2D(280, 50), "destiny"), new Font("Continuar", FONT_PATH + "Aero.ttf", 54, utility::WHITE), utility::INTER_BLUE, utility::PLAY));
	itens.push_back(new HighlightItem("MainMenu", new Rectangle(Vector2D(posx - 20, posy + 60), Vector2D(300, 50), "destiny"), new Font("Menu Principal", FONT_PATH + "Aero.ttf", 54, utility::WHITE), utility::INTER_BLUE, utility::MAIN_MENU));

	std::cout << "size: " << itens.size() << std::endl;

	this->getLayer("Background")->addGameObject(new Background("Background"));
	this->getLayer("Interaction")->addGameObject(new Menu("Paused", itens));
	this->getLayer("Interaction")->addGameObject(new TextItem(Vector2D(65, 40), Vector2D(300, 80), "Pausado", 54, FONT_PATH + "distortion_of_the_brain_and_mind.ttf", utility::GREEN, "Title"));
#if _DEBUG
	this->getLayer("Debug")->addGameObject(new FPS_HUD("FPS_HUD"));
#endif
}

PauseState::~PauseState()
{
}

void PauseState::execute_BTN_SPACE() {
	auto state = ((Menu*)this->getLayer("Interaction")->getGameObject("Paused"))->getCurrentHighLightItem()->getNextState();
	Command::select(state);
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
	Command::moveMenuUp((Menu*)this->getLayer("Interaction")->getGameObject("Paused"));
}
void PauseState::execute_DOWN() {
	Command::moveMenuDown((Menu*)this->getLayer("Interaction")->getGameObject("Paused"));
}
