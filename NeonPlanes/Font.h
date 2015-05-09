#pragma once

#include "core.h"

class Font
{
public:
	Font(std::string value, std::string font, Uint8 size, SDL_Color color);
	virtual ~Font();

	std::string getValue() const;
	std::string getFont() const;
	Uint8 getSize() const;
	SDL_Color getColor() const;

	void setValue(std::string value);
	void setColor(SDL_Color color);

private:
	std::string value;
	std::string font;
	Uint8 size;
	SDL_Color color;
};
