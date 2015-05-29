#include "Player.h"

Player::Player(std::string name) : Airplane(name)
{
	this->velocity = 3;
	this->addComponent(new Rectangle(Vector2D(200,300),Vector2D(64,45),"destiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("destiny"), "player.png", "StaticSprite"));
	this->addBehavior(new MoveBehavior("moveBehavior", Vector2D(0, 0), (Rectangle*)this->getComponent("destiny"), &this->collided));
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

void Player::move(Vector2D vel) {
	((MoveBehavior*)this->getBehavior("moveBehavior"))->changeVelocity(vel);
}

Vector2D Player::getCurrentVelocity() {
	return ((MoveBehavior*)this->getBehavior("moveBehavior"))->getVelocity();
}
