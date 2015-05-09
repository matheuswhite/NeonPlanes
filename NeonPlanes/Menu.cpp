#include "Menu.h"

Menu::Menu(std::string name, std::vector<Item*> itens) : itens(itens), currentItem(0), GameObject(name)
{
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

	this->addBehavior(new MenuBehavior(name, behaviors));
	this->addSprite(new MenuSprite(nullptr, "", name, sprites));

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

void Menu::addItem(Item* item) {
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