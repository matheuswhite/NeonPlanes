#include "DynamicTextSprite.h"

DynamicTextSprite::DynamicTextSprite(Rectangle* destiny, Font* font, std::string name) : Sprite(destiny, font->getFont(), name)
{
	this->font = font;
	this->texture = new Texture();
	this->texture->loadTTF(renderer, font);
}

DynamicTextSprite::~DynamicTextSprite()
{
}

void DynamicTextSprite::draw() {
	Graphics::render(nullptr, destiny->getRectSDL(), this->texture->getTexture());
}

Font* DynamicTextSprite::getFont() const {
	return this->font;
}

void DynamicTextSprite::updateValue(std::string value) {
	this->font->setValue(value);

	delete this->texture;
	this->texture = new Texture();
	this->texture->loadTTF(renderer, this->font);
}

void DynamicTextSprite::setColor(SDL_Color color) {
	this->font->setColor(color);

	delete this->texture;
	this->texture = new Texture();
	this->texture->loadTTF(renderer, this->font);
}