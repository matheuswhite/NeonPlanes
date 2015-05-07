#include "Background.h"

Background::Background(std::string name) : GameObject(name)
{
	this->addComponent(new Rectangle(Vector2D(0,610), Vector2D(420,590), "source"));

	this->addSprite(new VerticalScrollingSprite((Rectangle*)this->getComponent("source"), nullptr, "background.png", "background", -13));
}

Background::~Background()
{
}
