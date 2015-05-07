#include "FPS_HUD.h"

FPS_HUD::FPS_HUD(std::string name) : GameObject(name)
{
	this->addSprite(new StaticTextSprite(new Rectangle(Vector2D(20, 20), Vector2D(70, 40), "destinyName"), new Font("FPS: ", FONT_PATH + "Aero.ttf", 28, utility::RED), "Static"));
	this->addSprite(new DynamicTextSprite(new Rectangle(Vector2D(90, 20), Vector2D(40, 40), "destinyValue"), new Font("", FONT_PATH + "Aero.ttf", 28, utility::RED), "Dynamic"));
}

FPS_HUD::~FPS_HUD()
{
}

void FPS_HUD::updateFPS(Uint8 fps) {
	for each (auto var in this->sprites) {
		if (var->getName() == "Dynamic") {
			auto str = std::to_string(fps);
			((DynamicTextSprite*)var)->updateValue(str);
		}
	}
}