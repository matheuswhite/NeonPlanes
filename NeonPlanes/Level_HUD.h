#pragma once

#include "GameObject.h"
#include "StaticTextSprite.h"
#include "DynamicTextSprite.h"
#include "ColoredBackgroundSprite.h"

class Level_HUD : public GameObject
{
public:
	Level_HUD(std::string name);
	virtual ~Level_HUD();

	int getLevel() const;
	int getMaxLevel() const;
	void increaseLevel();
	void clear();
	std::string formatOutput();
	void setLevelColor();

private:
	SDL_Color prevBarColor;
	SDL_Color currentBarColor;
	SDL_Color nameColor;
	std::vector<SDL_Color> colors;

	int level;
	const int MAX_LEVEL = 999;
};
