#include "Light.h"

Light::Light(std::string name, Vector2D pos) : GameObject(name)
{
	this->pos = pos;
}

Light::~Light()
{
}
