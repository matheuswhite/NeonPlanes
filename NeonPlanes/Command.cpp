#include "Command.h"

Command::Command() {

}

Command::~Command() {

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