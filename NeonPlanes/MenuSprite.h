#pragma once

#include "Sprite.h"

class MenuSprite : public Sprite
{
public:
	MenuSprite(Rectangle* destiny, std::string pathFile, std::string name, std::vector<Sprite*> sprites);
	virtual ~MenuSprite();

	void draw() override;

	void addSprite(Sprite* sprite);
private:
	std::vector<Sprite*> sprites;
};
