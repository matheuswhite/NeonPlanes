#include "StaticTextSprite.h"

StaticTextSprite::StaticTextSprite(Rectangle* destiny, Font* font, std::string name) : Sprite(destiny, font->getFont(), name)
{
	this->font = font;
	this->texture = new Texture();
	this->texture->loadTTF(renderer, font);
}

StaticTextSprite::~StaticTextSprite()
{
}

void StaticTextSprite::draw() {
	Graphics::render(nullptr, destiny->getRectSDL(), this->texture->getTexture());
}

Font* StaticTextSprite::getFont() const {
	return this->font;
}