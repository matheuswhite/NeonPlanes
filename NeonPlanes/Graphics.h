#pragma once

#include "Tool.h"
#include "Texture.h"
#include "Game.h"

class Graphics : public Tool
{
public:
	Graphics();
	virtual ~Graphics();

	static void sinAnimation(double limit, Texture* texture);
};
