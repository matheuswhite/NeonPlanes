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

void Command::shoot() {
#if _DEBUG
	std::cout << "Shoot!" << std::endl;
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
	std::cout << "Resume" << std::endl;
#else

#endif
}

void Command::pause() {
#if _DEBUG
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

void Command::select() {
#if _DEBUG
	std::cout << "Select" << std::endl;
#else

#endif
}

void Command::moveMenuUp() {
#if _DEBUG
	std::cout << "MenuUp" << std::endl;
#else

#endif
}

void Command::moveMenuDown() {
#if _DEBUG
	std::cout << "MenuDown" << std::endl;
#else

#endif
}
