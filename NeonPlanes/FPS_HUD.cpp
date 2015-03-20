#include "FPS_HUD.h"

FPS_HUD::FPS_HUD(Uint32 id) : GameObject(id)
{
	this->addComponent(new TextSprite(new Rectangle(new Vector2D(20, 20), new Vector2D(50, 20)), (char*)fps, "Sans.ttf", 24, utility::RED));
}

FPS_HUD::~FPS_HUD()
{
}

void FPS_HUD::updateFPS(Uint8 fps) {
	fps = fps;
}