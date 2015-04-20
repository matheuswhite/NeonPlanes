#include "Sprite.h"

class VerticalScrollingSprite : public Sprite
{
public:
	VerticalScrollingSprite(Rectangle* destiny, std::string name, float velocity);
	virtual ~VerticalScrollingSprite();

	void draw();

	Vector2D getVelocity() const;
	void changeVelocity(float velocity);
private:
	Vector2D velocity;
};