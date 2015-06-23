#include "Player.h"

Player::Player(std::string name) : Airplane(name)
{
	this->velocity = 4;
	this->addComponent(new Rectangle(Vector2D(180,270),Vector2D(64,45),"destiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("destiny"), "player.png", "StaticSprite"));
	this->addBehavior(new PlayerMoveBehavior("moveBehavior", Vector2D(0, 0), (Rectangle*)this->getComponent("destiny"), Vector2D(64, 45)));
}

Player::~Player()
{
}

void Player::shoot() {
	this->addPending(new WhiteProjectile("whiteProjectile" + std::to_string(objectValue), ((Rectangle*)this->getComponent("destiny"))->getPosition()));
	if (objectValue >= LLONG_MAX) {
		this->objectValue = 0;
	}
	else {
		this->objectValue++;
	}
}

void Player::useLightWall() {
	this->addPending(new WhiteLight("whiteLight" + std::to_string(objectValue), ((Rectangle*)this->getComponent("destiny"))->getPosition()));
	if (objectValue >= LLONG_MAX) {
		this->objectValue = 0;
	}
	else {
		this->objectValue++;
	}
}

void Player::move(Vector2D vel) {
	((PlayerMoveBehavior*)this->getBehavior("moveBehavior"))->changeVelocity(vel);
}

Vector2D Player::getCurrentVelocity() {
	return ((PlayerMoveBehavior*)this->getBehavior("moveBehavior"))->getVelocity();
}
