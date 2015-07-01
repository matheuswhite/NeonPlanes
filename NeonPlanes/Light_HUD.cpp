#include "Light_HUD.h"

Light_HUD::Light_HUD(std::string name) : GameObject(name)
{

	this->addSprite(new StaticTextSprite(new Rectangle(Vector2D(15, 10), Vector2D(70, 30), "destiny"), new Font("Luz", FONT_PATH + "Aero.ttf", 62, utility::YELLOW), "StaticTextSprite"));
	this->addSprite(new DynamicTextSprite(new Rectangle(Vector2D(18, 50), Vector2D(90, 30), "destiny"), new Font("100%", FONT_PATH + "Aero.ttf", 62, utility::YELLOW), "DynamicTextSprite"));
	
	this->decreaseTimer = new SlaveTimer(30, "decreaseTimer");
	this->decreaseTimer->pause();

	this->lightLevel = 100;
}

Light_HUD::~Light_HUD()
{
}

void Light_HUD::setDecrease(bool* isDecrease) {
	this->isDecrease = isDecrease;
}

bool Light_HUD::isLightLevelPositive() {
	return ((this->lightLevel > 0) && (this->lightLevel <= 100));
}

void Light_HUD::updateLightLevel() {
	if (*this->isDecrease) {
		this->decreaseLightLevel();

		((DynamicTextSprite*)this->getSprite("DynamicTextSprite"))->updateValue(this->formatOutput() + std::to_string(this->lightLevel) + "%");
	}
	else {
		this->decreaseTimer->pause();
	}
}

bool* Light_HUD::getIsDecrease() const {
	return this->isDecrease;
}

std::string Light_HUD::formatOutput() {
	std::string output;
	output.clear();

	if (this->lightLevel < 10) {
		output = "00";
	}
	else if (this->lightLevel < 100) {
		output = "0";
	}

	return output;
}

void Light_HUD::decreaseLightLevel() {
	if (this->lightLevel > 0 && this->lightLevel <= 100) {
		if (this->decreaseTimer->isPaused()) {
			this->decreaseTimer->loop();
		}

		if (this->decreaseTimer->isFinish()) {
			this->lightLevel--;
			this->decreaseTimer->loop();
		}
	}
	else {
		this->decreaseTimer->loop();
		this->decreaseTimer->pause();
	}
}

void Light_HUD::fillLightLevel() {
	this->lightLevel = 100;

	auto sprite = (DynamicTextSprite*)this->getSprite("DynamicTextSprite");
	sprite->updateValue(this->formatOutput() + std::to_string(this->lightLevel) + "%");
}
