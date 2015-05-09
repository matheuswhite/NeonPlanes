#pragma once

#include "DynamicTextSprite.h"

class HighlightTextSprite : public DynamicTextSprite
{
public:
	HighlightTextSprite(Rectangle* destiny, Font* font, std::string name, SDL_Color highlightColor);
	virtual ~HighlightTextSprite();

	SDL_Color getHighlightColor() const;
	SDL_Color getNormalColor() const;

	void highlight();
	void turnOff();
private:
	SDL_Color highlightColor;
	SDL_Color normalColor;
};
