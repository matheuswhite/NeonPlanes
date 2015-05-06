#pragma once

#include "GameObject.h"
#include "StaticSprite.h"

class AirPlane : public GameObject
{
public:
	AirPlane(Uint32 id, std::string name);
	virtual ~AirPlane();

protected:

};
