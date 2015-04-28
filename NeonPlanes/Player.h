#pragma once

#include "GameObject.h"
#include "StaticSprite.h"

class Player : public GameObject
{
public:
	Player(Uint32 id, std::string name);
	virtual ~Player();

private:

};
