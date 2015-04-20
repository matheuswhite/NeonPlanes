#include "Sprite.h"

class StaticSprite : public Sprite
{
public:
	StaticSprite(Rectangle* destiny, std::string name);
	virtual ~StaticSprite();

	void draw();
};
