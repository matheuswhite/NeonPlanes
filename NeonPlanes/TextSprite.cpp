#include "TextSprite.h"

TextSprite::TextSprite(Rectangle* destiny, Font* font) : Sprite(destiny)
{
	this->font = font;
	this->texture = new Texture();
	this->texture->loadTTF(renderer, font);
}

TextSprite::~TextSprite()
{
}

void TextSprite::draw() {
	Graphics::render(nullptr, destiny->getRectSDL(), this->texture->getTexture());
}

Font* TextSprite::getFont() const {
	return this->font;
}