#include "Level_HUD.h"

bool operator==(SDL_Color f, const SDL_Color s) {
	return (f.r == s.r) && (f.g == s.g) && (f.b == s.b) && (f.a == s.a);
}

Level_HUD::Level_HUD(std::string name) : prevBarColor(utility::BLACK), level(1), GameObject(name)
{
	this->colors = { utility::YELLOW, utility::BLUE, utility::RED, utility::GREEN, utility::LIGHT_BLUE };
	auto colorNum = rand() % this->colors.size();
	this->currentBarColor = this->colors.at(colorNum);
	this->nameColor = utility::WHITE;

	if ( this->currentBarColor == utility::YELLOW || this->currentBarColor == utility::LIGHT_BLUE) {
		this->nameColor = utility::INTER_GRAY;
	}

	this->addSprite(new ColoredBackgroundSprite(new Rectangle(Vector2D(0, BOTTOM_BOUND), Vector2D(SCREEN_WIDTH, SCREEN_HEIGHT - BOTTOM_BOUND), "destiny"), "ColoredBackgroundSprite", this->currentBarColor));
	this->addSprite(new StaticTextSprite(new Rectangle(Vector2D(130, BOTTOM_BOUND + 15), Vector2D(100, 30), "destiny"), new Font("Level", FONT_PATH + "Aero.ttf", 62, this->nameColor), "StaticTextSprite"));
	this->addSprite(new DynamicTextSprite(new Rectangle(Vector2D(240, BOTTOM_BOUND + 15), Vector2D(60, 30), "destiny"), new Font("001", FONT_PATH + "Aero.ttf", 62, this->nameColor), "DynamicTextSprite"));
}

Level_HUD::~Level_HUD()
{
	this->sprites.clear();
}

int Level_HUD::getLevel() const {
	return this->level;
}

int Level_HUD::getMaxLevel() const {
	return this->MAX_LEVEL;
}

void Level_HUD::increaseLevel() {
	if (this->level == this->MAX_LEVEL) {

	}
	else if (this->level < this->MAX_LEVEL) {
		this->level++;
		this->setLevelColor();

		std::string value = this->formatOutput() + std::to_string(this->level);
		((DynamicTextSprite*)this->getSprite("DynamicTextSprite"))->updateValue(value);
		((DynamicTextSprite*)this->getSprite("DynamicTextSprite"))->setColor(this->nameColor);
		((StaticTextSprite*)this->getSprite("StaticTextSprite"))->setColor(this->nameColor);
		((ColoredBackgroundSprite*)this->getSprite("ColoredBackgroundSprite"))->setColor(this->currentBarColor);
	}
}

void Level_HUD::setLevelColor() {
	SDL_Color testColor;
	do {
		auto randColor = rand() % this->colors.size();
		testColor = colors.at(randColor);
	} while (testColor == prevBarColor);
	
	this->prevBarColor = this->currentBarColor;
	this->currentBarColor = testColor;
	this->nameColor = utility::WHITE;

	if (this->currentBarColor == utility::YELLOW || this->currentBarColor == utility::LIGHT_BLUE) {
		this->nameColor = utility::INTER_GRAY;
	}
}

std::string Level_HUD::formatOutput() {
	std::string output;
	output.clear();

	if (this->level < 10) {
		output = "00";
	}
	else if (this->level < 100) {
		output = "0";
	}

	return output;
}

void Level_HUD::clear() {
	this->active = false;
}