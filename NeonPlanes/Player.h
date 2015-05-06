#pragma once

#include "AirPlane.h"

class Player : public AirPlane
{
public:
	Player(Uint32 id, std::string name);
	virtual ~Player();

private:

};
