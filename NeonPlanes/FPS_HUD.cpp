#include "FPS_HUD.h"

FPS_HUD::FPS_HUD(std::string name) : GameObject(name)
{
	this->addComponent(new Rectangle(Vector2D(20, SCREEN_HEIGHT - 100), Vector2D(70, 40), "destinyName"));
	this->addComponent(new Rectangle(Vector2D(90, SCREEN_HEIGHT - 100), Vector2D(40, 40), "destinyValue"));

	this->addSprite(new StaticTextSprite((Rectangle*)this->getComponent("destinyName"), new Font("FPS: ", FONT_PATH + "Aero.ttf", 28, utility::RED), "StaticTextSprite"));
	this->addSprite(new DynamicTextSprite((Rectangle*)this->getComponent("destinyValue"), new Font("", FONT_PATH + "Aero.ttf", 28, utility::RED), "DynamicTextSprite"));
}

FPS_HUD::~FPS_HUD()
{
}

void FPS_HUD::updateFPS(Uint8 fps) {
	for each (auto var in this->sprites) {
		if (var->getName() == "DynamicTextSprite") {
			auto str = std::to_string(fps);
			((DynamicTextSprite*)var)->updateValue(str);
		}
	}
}