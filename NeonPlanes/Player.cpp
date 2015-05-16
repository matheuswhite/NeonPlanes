#include "Player.h"

Player::Player(std::string name) : GameObject(name)
{
	objectValue = 0;
	this->addComponent(new Rectangle(Vector2D(200,300),Vector2D(64,45),"destiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("destiny"), "player.png", "StaticSprite"));
}

Player::~Player()
{
}

void Player::shoot() {
	this->addPending(new WhiteProjectile("whiteProjectile" + objectValue, ((Rectangle*)this->getComponent("destiny"))->getPosition()));
	if (objectValue >= LLONG_MAX) {
		this->objectValue = 0;
	}
	else {
		this->objectValue++;
	}
}

void Player::useLightWall() {
	this->addPending(new WhiteLight("whiteLight" + objectValue, ((Rectangle*)this->getComponent("destiny"))->getPosition()));
	if (objectValue >= LLONG_MAX) {
		this->objectValue = 0;
	}
	else {
		this->objectValue++;
	}
}