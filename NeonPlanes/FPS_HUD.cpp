#include "FPS_HUD.h"

FPS_HUD::FPS_HUD(Uint32 id) : GameObject(id)
{
	this->addComponent(new TextSprite(new Rectangle(new Vector2D(20, 20), new Vector2D(50, 20)), new Font("", FONT_PATH + "Sans.ttf", 24, utility::RED)));
}

FPS_HUD::~FPS_HUD()
{
}

void FPS_HUD::updateFPS(Uint8 fps) {
	auto temp = (TextSprite*)this->getComponent("class TextSprite");
	auto font = temp->getFont();
	
	font->setValue("FPS: " + fps);
	temp->getTexture()->loadTTF(renderer, temp->getFont());
}