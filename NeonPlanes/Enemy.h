#pragma once

#include "AirPlane.h"

class Enemy : public AirPlane
{
public:
	Enemy(Uint32 id, std::string name);
	virtual ~Enemy();

protected:

};
