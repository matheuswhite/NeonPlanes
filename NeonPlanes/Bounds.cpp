#include "Bounds.h"

Bounds::Bounds(std::string name, Rectangle* destiny) : GameObject(name)
{
	this->addComponent(destiny);
}

Bounds::~Bounds()
{
}
