#include "Command.h"

Command::Command() {

}

Command::~Command() {

}

void Command::stop(Player* player, bool vertical) {
	auto vel = player->getCurrentVelocity();
	if (vertical) {
		player->move(Vector2D(vel.x, 0));
	}
	else {
		player->move(Vector2D(0, vel.y));
	}
}

void Command::totalStop(Player* player) {
	player->move(Vector2D(0, 0));
}

void Command::shoot(Player* player) {
	player->shoot();
}

void Command::useLightWall(Player* player) {
	player->useLightWall();
}

void Command::moveUp(Player* player) {
	player->move(Vector2D(player->getCurrentVelocity().x, -player->getVelocityValue()));
}

void Command::moveDown(Player* player) {
	player->move(Vector2D(player->getCurrentVelocity().x, player->getVelocityValue()));
}

void Command::doNothing() {
}

void Command::resume() {
	Notifier::notify(utility::PLAY);
}

void Command::pause() {
	Notifier::notify(utility::PAUSE);
}

void Command::moveLeft(Player* player) {
	player->move(Vector2D(-player->getVelocityValue(), player->getCurrentVelocity().y));
}

void Command::moveRight(Player* player) {
	player->move(Vector2D(player->getVelocityValue(), player->getCurrentVelocity().y));
}

void Command::select(Uint8 nextState) {
	Notifier::notify(nextState);
}

void Command::moveMenuUp(Menu* menu) {
	menu->prevItem();
}

void Command::moveMenuDown(Menu* menu) {
	menu->nextItem();
}
