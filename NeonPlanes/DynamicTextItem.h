#pragma once

#include "GameObject.h"
#include "DynamicTextSprite.h"

class DynamicTextItem : public GameObject
{
public:
	DynamicTextItem(Vector2D pos, Vector2D size, std::string value, int sizeLettre, std::string font, SDL_Color color, std::string name);
	virtual ~DynamicTextItem();

	void updateValue(std::string newValue);
};
