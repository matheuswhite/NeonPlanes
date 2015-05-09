#include "HighlightItem.h"

HighlightItem::HighlightItem(std::string name, Rectangle* destiny, Font* font, SDL_Color highlightColor) : Item(name)
{
	this->addSprite(new HighlightTextSprite(destiny, font, "HighlightTextSprite", highlightColor));
}

HighlightItem::~HighlightItem()
{
}

void HighlightItem::highlight() {
	((HighlightTextSprite*)this->getSprite("HighlightTextSprite"))->highlight();
}

void HighlightItem::turnOff() {
	((HighlightTextSprite*)this->getSprite("HighlightTextSprite"))->turnOff();
}
