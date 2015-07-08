#include "PlayerMoveBehavior.h"

PlayerMoveBehavior::PlayerMoveBehavior(std::string name, Vector2D velocity, Rectangle* destiny, Vector2D airplaneSize) : airplaneSize(airplaneSize), velocity(velocity), destiny(destiny), Behavior(name)
{
	this->next_position = this->destiny->getPosition() + this->velocity;
}

PlayerMoveBehavior::~PlayerMoveBehavior()
{
}

void PlayerMoveBehavior::changeVelocity(Vector2D velocity) {
	this->velocity = velocity;
}

Vector2D PlayerMoveBehavior::getVelocity() const {
	return this->velocity;
}

void PlayerMoveBehavior::run() {
	bool internCollided_x;
	bool internCollided_y;


	if ((this->velocity.x < 0 && this->next_position.x < 0) ||
		(this->velocity.x > 0 && this->next_position.x > SCREEN_WIDTH - airplaneSize.x)) 
	{
		internCollided_x = true;
	}
	else internCollided_x = false;


	if ((this->velocity.y < 0 && this->next_position.y < TOP_BOUND) ||
		(this->velocity.y > 0 && this->next_position.y > BOTTOM_BOUND - airplaneSize.x)) 
	{
		internCollided_y = true;
	}
	else internCollided_y = false;


	if (internCollided_x && !internCollided_y) 
	{
		this->destiny->changePosition(Vector2D(this->destiny->getPosition().x, this->destiny->getPosition().y + velocity.y));
		this->next_position = Vector2D(this->next_position.x, this->destiny->getPosition().y + this->velocity.y);
	}
	else if (!internCollided_x && internCollided_y) 
	{
		this->destiny->changePosition(Vector2D(this->destiny->getPosition().x + velocity.x, this->destiny->getPosition().y));
		this->next_position = Vector2D(this->destiny->getPosition().x + this->velocity.x, this->destiny->getPosition().y);
	}
	else if (!internCollided_x && !internCollided_y) 
	{
		this->destiny->changePosition(this->destiny->getPosition() + velocity);
		this->next_position = this->destiny->getPosition() + this->velocity;
	}
}