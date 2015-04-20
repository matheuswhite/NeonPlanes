#pragma once

#include "Rectangle.h"
#include "Texture.h"

class Sprite : public Component
{
public:
	Sprite(Rectangle* destiny, std::string name) : destiny(destiny), name(name) {}
	virtual ~Sprite() 
	{
		delete texture;
		delete source;
		delete destiny;
	}

	virtual void draw() = 0;

	Texture* getTexture() const { return this->texture; }
	Rectangle* getSource() const { return this->source; }
	Rectangle* getDestiny() const { return this->destiny; }
	std::string getName() const { return this->name; }

protected:
	Texture* texture;
	Rectangle* source;
	Rectangle* destiny;
	std::string name;
};

