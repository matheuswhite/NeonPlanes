#include "HighlightTextSprite.h"

HighlightTextSprite::HighlightTextSprite(Rectangle* destiny, Font* font, std::string name, SDL_Color highlightColor) : highlightColor(highlightColor), DynamicTextSprite(destiny, font, name)
{
	this->normalColor = font->getColor();
}

HighlightTextSprite::~HighlightTextSprite()
{
}

SDL_Color HighlightTextSprite::getHighlightColor() const {
	return this->highlightColor;
}

void HighlightTextSprite::highlight() {
	this->font->setColor(this->highlightColor);

	delete this->texture;
	this->texture = new Texture();
	this->texture->loadTTF(renderer, this->font);
}

void HighlightTextSprite::turnOff() {
	this->font->setColor(this->normalColor);

	delete this->texture;
	this->texture = new Texture();
	this->texture->loadTTF(renderer, this->font);
}

SDL_Color HighlightTextSprite::getNormalColor() const {
	return this->normalColor;
}