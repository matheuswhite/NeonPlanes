#pragma once

#include "Component.h"
#include "Graphics.h"
#include "Rectangle.h"

class Sprite : public Component
{
public:
	Sprite(Rectangle* destiny) : destiny(destiny) {}
	virtual ~Sprite() 
	{
		delete source;
		delete destiny;
		delete texture;
	}

	virtual void draw() = 0;

protected:
	Texture* texture;
	Rectangle* source;
	Rectangle* destiny;
};

