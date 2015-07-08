#pragma once

#include "Sprite.h"

class StaticSprite : public Sprite
{
public:
	StaticSprite(Rectangle* destiny, std::string pathImage, std::string name);
	virtual ~StaticSprite();

	void draw() override;
};
