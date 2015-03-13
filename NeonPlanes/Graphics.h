#pragma once

#include "System.h"
#include "Texture.h"
#include "Game.h"

class Graphics : public System
{
public:
	Graphics();
	virtual ~Graphics();

	void sinAnimation(double limit, Texture* texture);
private:

};
