#pragma once

#include "GameObject.h"
#include "StaticSprite.h"
#include "MoveBehavior.h"

class Light : public GameObject
{
public:
	Light(std::string name, Vector2D pos);
	virtual ~Light();

protected:
	Vector2D pos;
};
