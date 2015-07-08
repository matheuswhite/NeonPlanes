#pragma once

#include "GameObject.h"
#include "StaticTextSprite.h"

class TextItem : public GameObject
{
public:
	TextItem(Vector2D pos, Vector2D size, std::string value, int sizeLettre, std::string font, SDL_Color color, std::string name);
	virtual ~TextItem();
};

