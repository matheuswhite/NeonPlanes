#include "Distance_HUD.h"

Distance_HUD::Distance_HUD(std::string name, int milisecond_step, int distance_step) : GameObject(name), milisecond_step(milisecond_step), distance_step(distance_step)
{
	this->totalDistance = 0;

	auto color = utility::BLACK;
	auto size_y = 30;
	this->addSprite(new ColoredBackgroundSprite(new Rectangle(Vector2D(0, 0), Vector2D(SCREEN_WIDTH, TOP_BOUND), "destiny"), "ColoredBackgroundSprite", color));
	this->addSprite(new StaticTextSprite(new Rectangle(Vector2D(SCREEN_WIDTH - 160, 10), Vector2D(150, size_y), "destiny"), new Font("Distância", FONT_PATH + "Aero.ttf", 60, utility::YELLOW), "StaticTextSprite"));
	this->addSprite(new DynamicTextSprite(new Rectangle(Vector2D(SCREEN_WIDTH - 85, 50), Vector2D(70, size_y), "destiny"), new Font("000", FONT_PATH + "Aero.ttf", 60, utility::YELLOW), "DynamicTextSprite"));

	this->timer = new SlaveTimer(milisecond_step, "DistanceTimer");
}

Distance_HUD::~Distance_HUD()
{
	this->sprites.clear();

	delete this->timer;
	this->timer = nullptr;
}

void Distance_HUD::updateDistance() {
	if (this->timer->isFinish()) {
		this->totalDistance += this->distance_step;

		auto sprite = (DynamicTextSprite*)this->getSprite("DynamicTextSprite");
		sprite->updateValue(this->formatOutput());

		this->timer->loop();
	}
}

unsigned long long int Distance_HUD::getTotalDistance() const {
	return this->totalDistance;
}

std::string Distance_HUD::formatOutput() {
	if (this->totalDistance < 1000) {
		//normal
		this->distance = this->totalDistance;
		this->distanceModifier = ' ';
	}
	else if (this->totalDistance >= 1000 && this->totalDistance < 1000000) {
		//kilo
		this->distance = this->totalDistance / 1000;
		this->distanceModifier = 'K';
	}
	else if (this->totalDistance >= 1000000 && this->totalDistance < 1000000000) {
		//mega
		this->distance = this->totalDistance / 1000000;
		this->distanceModifier = 'M';
	}
	else if (this->totalDistance >= 1000000000 && this->totalDistance < 1000000000000) {
		//giga
		this->distance = this->totalDistance / 1000000000;
		this->distanceModifier = 'G';
	}
	else if (this->totalDistance >= 1000000000000 && this->totalDistance < 1000000000000000) {
		//tera
		this->distance = this->totalDistance / 1000000000000;
		this->distanceModifier = 'T';
	}
	else {
		return "MAX!";
	}

	return this->addZeros() + std::to_string(this->distance) + this->distanceModifier;
}

std::string Distance_HUD::addZeros() {
	std::string output;
	output.clear();

	if (this->distance < 10) {
		output = "00";
	}
	else if (this->distance < 100) {
		output = "0";
	}

	return output;
}