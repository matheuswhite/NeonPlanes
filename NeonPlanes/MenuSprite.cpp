#include "MenuSprite.h"

MenuSprite::MenuSprite(Rectangle* destiny, std::string pathFile, std::string name, std::vector<Sprite*> sprites) : sprites(sprites), Sprite(destiny, pathFile, name)
{
}

MenuSprite::~MenuSprite()
{
}

void MenuSprite::draw() {
	for each (auto var in this->sprites)
	{
		var->draw();
	}
}

void MenuSprite::addSprite(Sprite* sprite) {
	this->sprites.push_back(sprite);
}