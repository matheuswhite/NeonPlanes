#pragma once

#include "core.h"
#include "Vector2D.h"
#include "Game.h"

class Texture
{
public:
	Texture(std::string pathFile);
	virtual ~Texture();

	SDL_Texture* getTexture() const;

private:
	void loadFromFile(SDL_Renderer* renderer);
	void free();

	SDL_Texture* texture;
	std::string pathFile;
};
