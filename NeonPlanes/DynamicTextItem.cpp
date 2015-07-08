#include "DynamicTextItem.h"

DynamicTextItem::DynamicTextItem(Vector2D pos, Vector2D size, std::string value, int sizeLettre, std::string font, SDL_Color color, std::string name) : GameObject(name)
{
	this->addComponent(new Rectangle(pos, size, "destiny"));
	this->addSprite(new DynamicTextSprite((Rectangle*)this->getComponent("destiny"), new Font(value, font, sizeLettre, color), "DynamicTextSprite"));
}

DynamicTextItem::~DynamicTextItem()
{
}

void DynamicTextItem::updateValue(std::string newValue) {
	auto sprite = this->getSprite("DynamicTextSprite");
	((DynamicTextSprite*)sprite)->updateValue(newValue);
}