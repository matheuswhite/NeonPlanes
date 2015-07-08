#include "TextItem.h"

TextItem::TextItem(Vector2D pos, Vector2D size, std::string value, int sizeLettre, std::string font, SDL_Color color, std::string name) : GameObject(name)
{
	this->addComponent(new Rectangle(pos, size, "destiny"));
	this->addSprite(new StaticTextSprite((Rectangle*)this->getComponent("destiny"), new Font(value, font, sizeLettre, color), "StaticTextSprite"));
}

TextItem::~TextItem()
{
}
