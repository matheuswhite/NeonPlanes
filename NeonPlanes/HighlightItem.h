#pragma once

#include "HighlightTextSprite.h"
#include "GameObject.h"

class HighlightItem : public GameObject
{
public:
	HighlightItem(std::string name, Rectangle* destiny, Font* font, SDL_Color highlightColor);
	virtual ~HighlightItem();

	void highlight();
	void turnOff();
};
