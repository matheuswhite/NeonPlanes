#include "Command.h"

Command::Command() {

}

Command::~Command() {

}

void Command::stop(Player* player) {
#if _DEBUG
	player->move(Vector2D(0, 0));
#else

#endif
}

void Command::shoot(Player* player) {
#if _DEBUG
	player->shoot();
#else

#endif
}

void Command::useLightWall(Player* player) {
#if _DEBUG
	player->useLightWall();
#else

#endif
}

void Command::moveUp(Player* player) {
#if _DEBUG
	player->move(Vector2D(0, -player->getVelocityValue()));
	std::cout << "Up" << std::endl;
#else

#endif
}

void Command::moveDown(Player* player) {
#if _DEBUG
	player->move(Vector2D(0, player->getVelocityValue()));
	std::cout << "Down" << std::endl;
#else

#endif
}

void Command::doNothing() {
#if _DEBUG
	std::cout << "DoNothing" << std::endl;
#else

#endif
}

void Command::resume() {
#if _DEBUG
	Notifier::notify(utility::PLAY);
#else

#endif
}

void Command::pause() {
#if _DEBUG
	Notifier::notify(utility::PAUSE);
#else

#endif
}

void Command::moveLeft(Player* player) {
#if _DEBUG
	player->move(Vector2D(-player->getVelocityValue(), 0));
	std::cout << "Left" << std::endl;
#else

#endif
}

void Command::moveRight(Player* player) {
#if _DEBUG
	player->move(Vector2D(player->getVelocityValue(), 0));
	std::cout << "Right" << std::endl;
#else

#endif
}

void Command::select(Uint8 nextState) {
#if _DEBUG
	Notifier::notify(nextState);
#else

#endif
}

void Command::moveMenuUp(Menu* menu) {
#if _DEBUG
	menu->prevItem();
#else

#endif
}

void Command::moveMenuDown(Menu* menu) {
#if _DEBUG
	menu->nextItem();
#else

#endif
}
