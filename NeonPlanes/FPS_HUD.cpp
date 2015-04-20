#include "FPS_HUD.h"

FPS_HUD::FPS_HUD(Uint32 id) : GameObject(id)
{
	this->addSprite(new TextSprite(new Rectangle(Vector2D(20, 20), Vector2D(70, 40), 0, "destinyName"), new Font("FPS: ", FONT_PATH + "BEBAS___.ttf", 24, utility::RED), "name"));
	this->addSprite(new TextSprite(new Rectangle(Vector2D(90, 20), Vector2D(40, 40), 0, "destinyValue"), new Font("", FONT_PATH + "BEBAS___.ttf", 24, utility::RED), "value"));
}

FPS_HUD::~FPS_HUD()
{
}

void FPS_HUD::updateFPS(Uint8 fps) {
	for each (auto var in this->sprites) {
		if (var->getName() == "value") {
			auto str = std::to_string(fps);
			((TextSprite*)var)->updateValue(str);
		}
	}
}