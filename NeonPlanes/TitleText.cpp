#include "TitleText.h"

TitleText::TitleText(std::string name) : GameObject(name)
{
	int posx = 70;
	int posy = 80;

	int factorx = 4;
	int factory = 4;

	this->addComponent(new Rectangle(Vector2D(posx, posy), Vector2D(250, 90), "destinyTop"));
	this->addComponent(new Rectangle(Vector2D(posx + 50, posy + 80), Vector2D(250, 90), "destinyBottom"));

	this->addSprite(new StaticTextSprite((Rectangle*)this->getComponent("destinyTop"), new Font("Neon", FONT_PATH + "FFFFORWA.TTF", 28, utility::GREEN), "StaticTextSpriteTop"));
	this->addSprite(new StaticTextSprite((Rectangle*)this->getComponent("destinyBottom"), new Font("Planes", FONT_PATH + "FFFFORWA.TTF", 28, utility::GREEN), "StaticTextSpriteBottom"));


	this->addComponent(new Rectangle(Vector2D(posx + factorx, posy + factory), Vector2D(250, 90), "destinyTop2"));
	this->addComponent(new Rectangle(Vector2D(posx + 50 + factorx, posy + 80 + factory), Vector2D(250, 90), "destinyBottom2"));

	this->addSprite(new StaticTextSprite((Rectangle*)this->getComponent("destinyTop2"), new Font("Neon", FONT_PATH + "FFFFORWA.TTF", 28, utility::RED), "StaticTextSpriteTop2"));
	this->addSprite(new StaticTextSprite((Rectangle*)this->getComponent("destinyBottom2"), new Font("Planes", FONT_PATH + "FFFFORWA.TTF", 28, utility::RED), "StaticTextSpriteBottom2"));


	this->addComponent(new Rectangle(Vector2D(posx + (factorx * 2), posy + (factory * 2)), Vector2D(250, 90), "destinyTop3"));
	this->addComponent(new Rectangle(Vector2D(posx + 50 + (factorx * 2), posy + 80 + (factory*2)), Vector2D(250, 90), "destinyBottom3"));

	this->addSprite(new StaticTextSprite((Rectangle*)this->getComponent("destinyTop3"), new Font("Neon", FONT_PATH + "FFFFORWA.TTF", 28, utility::WHITE), "StaticTextSpriteTop3"));
	this->addSprite(new StaticTextSprite((Rectangle*)this->getComponent("destinyBottom3"), new Font("Planes", FONT_PATH + "FFFFORWA.TTF", 28, utility::WHITE), "StaticTextSpriteBottom3"));


	this->addComponent(new Rectangle(Vector2D(posx + (factorx * 3), posy + (factory * 3)), Vector2D(250, 90), "destinyTop4"));
	this->addComponent(new Rectangle(Vector2D(posx + 50 + (factorx * 3), posy + 80 + (factory * 3)), Vector2D(250, 90), "destinyBottom4"));

	this->addSprite(new StaticTextSprite((Rectangle*)this->getComponent("destinyTop4"), new Font("Neon", FONT_PATH + "FFFFORWA.TTF", 28, utility::YELLOW), "StaticTextSpriteTop4"));
	this->addSprite(new StaticTextSprite((Rectangle*)this->getComponent("destinyBottom4"), new Font("Planes", FONT_PATH + "FFFFORWA.TTF", 28, utility::YELLOW), "StaticTextSpriteBottom4"));


	this->addComponent(new Rectangle(Vector2D(posx + (factorx * 4), posy + (factory * 4)), Vector2D(250, 90), "destinyTop5"));
	this->addComponent(new Rectangle(Vector2D(posx + 50 + (factorx * 4), posy + 80 + (factory * 4)), Vector2D(250, 90), "destinyBottom5"));

	this->addSprite(new StaticTextSprite((Rectangle*)this->getComponent("destinyTop5"), new Font("Neon", FONT_PATH + "FFFFORWA.TTF", 28, utility::BLUE), "StaticTextSpriteTop5"));
	this->addSprite(new StaticTextSprite((Rectangle*)this->getComponent("destinyBottom5"), new Font("Planes", FONT_PATH + "FFFFORWA.TTF", 28, utility::BLUE), "StaticTextSpriteBottom5"));
}

TitleText::~TitleText()
{
}
