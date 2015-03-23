#include "FPS_HUD.h"

FPS_HUD::FPS_HUD(Uint32 id) : GameObject(id)
{
	this->addComponent(new TextSprite(new Rectangle(new Vector2D(20, 20), new Vector2D(70, 30)), new Font("fps", FONT_PATH + "BEBAS___.ttf", 24, utility::RED)));
}

FPS_HUD::~FPS_HUD()
{
}

void FPS_HUD::updateFPS(Uint8 fps) {
	auto temp = (TextSprite*)this->getComponent("class TextSprite");
	auto str = "FPS: " + std::to_string(fps);
	temp->updateValue(str);
}