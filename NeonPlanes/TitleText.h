#pragma once

#include "GameObject.h"
#include "StaticTextSprite.h"

class TitleText : public GameObject
{
public:
	TitleText(std::string name);
	virtual ~TitleText();
};
