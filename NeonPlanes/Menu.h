#pragma once

#include "GameObject.h"
#include "HighlightItem.h"
#include "MenuBehavior.h"
#include "MenuSprite.h"

class Menu : public GameObject
{
public:
	Menu(std::string name, std::vector<Item*> itens);
	virtual ~Menu();
	
	void nextItem();
	void prevItem();

	void addItem(Item* item);
	void clearAllItem();
private:
	int currentItem;
	std::vector<Item*> itens;
};
