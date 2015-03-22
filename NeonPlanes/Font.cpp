#include "Font.h"

Font::Font(std::string value, std::string font, Uint8 size, SDL_Color color) : value(value), font(font), size(size), color(color)
{
}

Font::~Font()
{
}

std::string Font::getValue() const {
	return this->value;
}

std::string Font::getFont() const {
	return this->font;
}

Uint8 Font::getSize() const {
	return this->size;
}

SDL_Color Font::getColor() const {
	return this->color;
}

void Font::setValue(std::string value) {
	this->value = value;
}