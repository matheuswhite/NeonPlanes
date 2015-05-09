#pragma once

#include "HighlightTextSprite.h"
#include "Item.h"

class HighlightItem : public Item
{
public:
	HighlightItem(std::string name, Rectangle* destiny, Font* font, SDL_Color highlightColor);
	virtual ~HighlightItem();

	void highlight();
	void turnOff();
};
