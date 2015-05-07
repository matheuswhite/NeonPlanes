#pragma once

#include "GameObject.h"
#include "DynamicTextSprite.h"
#include "StaticTextSprite.h"

class FPS_HUD : public GameObject
{
public:
	FPS_HUD(std::string name);
	virtual ~FPS_HUD();

	void updateFPS(Uint8 fps);
};
