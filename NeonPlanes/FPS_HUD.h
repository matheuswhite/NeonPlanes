#pragma once

#include "GameObject.h"
#include "TextSprite.h"
#include "Rectangle.h"

class FPS_HUD : public GameObject
{
public:
	FPS_HUD(Uint32 id);
	virtual ~FPS_HUD();

	static void updateFPS(Uint8 fps);
private:
	static Uint8 fps;
};
