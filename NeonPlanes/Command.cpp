#include "Command.h"

Command::Command() {

}

Command::~Command() {

}

void Command::stop() {
#if _DEBUG
	std::cout << "Stop!" << std::endl;
#else

#endif
}

void Command::shoot(Player* player) {
#if _DEBUG
	player->shoot();
#else

#endif
}

void Command::useLightWall() {
#if _DEBUG
	std::cout << "Wall" << std::endl;
#else

#endif
}

void Command::moveUp() {
#if _DEBUG
	std::cout << "Up" << std::endl;
#else

#endif
}

void Command::moveDown() {
#if _DEBUG
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
	std::cout << "Resume" << std::endl;
#else

#endif
}

void Command::pause() {
#if _DEBUG
	Notifier::notify(utility::PAUSE);
	std::cout << "Pause" << std::endl;
#else

#endif
}

void Command::moveLeft() {
#if _DEBUG
	std::cout << "Left" << std::endl;
#else

#endif
}

void Command::moveRight() {
#if _DEBUG
	std::cout << "Right" << std::endl;
#else

#endif
}

void Command::select(Uint8 nextState) {
#if _DEBUG
	Notifier::notify(nextState);
	std::cout << "Select" << std::endl;
#else

#endif
}

void Command::moveMenuUp(Menu* menu) {
#if _DEBUG
	menu->prevItem();
	std::cout << "Up" << std::endl;
#else

#endif
}

void Command::moveMenuDown(Menu* menu) {
#if _DEBUG
	menu->nextItem();
	std::cout << "Down" << std::endl;
#else

#endif
}
