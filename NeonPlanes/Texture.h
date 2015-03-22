#pragma once

#include "Font.h"

class Texture
{
public:
	Texture();
	virtual ~Texture();

	SDL_Texture* getTexture() const;
	
	void loadImage(SDL_Renderer* renderer, std::string pathFile);
	void loadTTF(SDL_Renderer* renderer, Font* font);
private:
	void free();

	SDL_Texture* texture;
};