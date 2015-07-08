#pragma once

#include "GameObject.h"
#include "HighlightItem.h"
#include "MenuBehavior.h"
#include "MenuSprite.h"

class Menu : public GameObject
{
public:
	Menu(std::string name, std::vector<HighlightItem*> itens);
	virtual ~Menu();
	
	void nextItem();
	void prevItem();

	HighlightItem* getCurrentHighLightItem() const;

	void addItem(HighlightItem* item);
	void clearAllItem();
private:
	int currentItem;
	std::vector<HighlightItem*> itens;
};
