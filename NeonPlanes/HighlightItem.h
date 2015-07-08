#pragma once

#include "HighlightTextSprite.h"
#include "GameObject.h"

class HighlightItem : public GameObject
{
public:
	HighlightItem(std::string name, Rectangle* destiny, Font* font, SDL_Color highlightColor, Uint8 nextState);
	virtual ~HighlightItem();

	void highlight();
	void turnOff();

	Uint8 getNextState() const;
private:
	Uint8 nextState;
};
