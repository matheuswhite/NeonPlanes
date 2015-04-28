#pragma once

#include "GameObject.h"
#include "TextSprite.h"

class FPS_HUD : public GameObject
{
public:
	FPS_HUD(Uint32 id, std::string name);
	virtual ~FPS_HUD();

	void updateFPS(Uint8 fps);
};
