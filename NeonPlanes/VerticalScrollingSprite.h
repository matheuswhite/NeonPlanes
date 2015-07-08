#pragma once

#include "Sprite.h"

class VerticalScrollingSprite : public Sprite
{
public:
	VerticalScrollingSprite(Rectangle* source, Rectangle* destiny, std::string pathImage, std::string name, float velocity);
	virtual ~VerticalScrollingSprite();

	void draw() override;

	Vector2D getVelocity() const;
	void changeVelocity(float velocity);
private:
	Vector2D velocity;
	double init_pos;
};