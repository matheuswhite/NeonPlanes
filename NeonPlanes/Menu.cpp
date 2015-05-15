#include "Menu.h"

Menu::Menu(std::string name, std::vector<HighlightItem*> itens) : itens(itens), GameObject(name)
{
	this->currentItem = 0;
	std::vector<Sprite*> sprites;
	std::vector<Behavior*> behaviors;
	
	for each (auto var in this->itens)
	{
		for each (auto var2 in var->getVectorSprites())
		{
			sprites.push_back(var2);
		}
	}

	for each (auto var in this->itens)
	{
		for each (auto var2 in var->getVectorBaheviors())
		{
			behaviors.push_back(var2);
		}
	}

	this->addBehavior(new MenuBehavior("MenuBehavior", behaviors));
	this->addSprite(new MenuSprite(nullptr, "", "MenuBehavior", sprites));

	this->itens.at(0)->highlight();
}

Menu::~Menu()
{
}

void Menu::nextItem() {
	auto i = this->currentItem + 1;
	if (i < this->itens.size()) {
		this->itens.at(this->currentItem)->turnOff();
		this->itens.at(i)->highlight();
		this->currentItem = i;
	}
}

void Menu::prevItem() {
	auto i = this->currentItem - 1;
	if (i > 0) {
		this->itens.at(this->currentItem)->turnOff();
		this->itens.at(i)->highlight();
		this->currentItem = i;
	}
}

void Menu::addItem(HighlightItem* item) {
	for each (auto var in item->getVectorSprites())
	{
		((MenuSprite*)this->getSprite("MenuSprite"))->addSprite(var);
	}

	for each (auto var2 in item->getVectorBaheviors())
	{
		((MenuBehavior*)this->getBehavior("MenuBehavior"))->addBehavior(var2);
	}
}

void Menu::clearAllItem() {
	this->itens.clear();
}

HighlightItem* Menu::getCurrentHighLightItem() const {
	std::cout << std::endl;
	return this->itens.at(this->currentItem);
}