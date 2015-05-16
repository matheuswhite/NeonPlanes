#include "Player.h"

Player::Player(std::string name) : GameObject(name)
{
	this->addComponent(new Rectangle(Vector2D(200,300),Vector2D(64,45),"destiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("destiny"), "player.png", "StaticSprite"));
}

Player::~Player()
{
}
//64 x 45

void Player::shoot() {
	this->addPending(new WhiteProjectile("whiteProjectile", ((Rectangle*)this->getComponent("destiny"))->getPosition() ));
}

void Player::useLightWall() {
	this->addPending(new WhiteLight("whiteLight", ((Rectangle*)this->getComponent("destiny"))->getPosition()));
}