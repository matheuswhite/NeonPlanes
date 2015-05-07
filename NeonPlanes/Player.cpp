#include "Player.h"

Player::Player(std::string name) : AirPlane(name)
{
	this->addComponent(new Rectangle(Vector2D(200,300),Vector2D(64,45),0,"rectDestiny"));

	this->addSprite(new StaticSprite((Rectangle*)this->getComponent("rectDestiny"), "player.png", "player"));
}

Player::~Player()
{
}
//64 x 45