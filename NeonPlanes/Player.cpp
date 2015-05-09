#include "Player.h"

Player::Player(std::string name) : AirPlane(name)
{
	this->addComponent(new Rectangle(Vector2D(200,300),Vector2D(64,45),"destiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("destiny"), "player.png", "StaticSprite"));
}

Player::~Player()
{
}
//64 x 45

void Player::shoot() {
	this->addPending(std::make_shared<GameObject>(WhiteProjectile("whiteProjectile")));
}