#pragma once

#include "Game.h"

class Texture
{
public:
	Texture(std::string pathFile);
	Texture(SDL_Surface* surface);
	virtual ~Texture();

	SDL_Texture* getTexture() const;

private:
	void loadFromFile(SDL_Renderer* renderer, SDL_Surface* loadedSurface);
	void free();

	SDL_Texture* texture;
	std::string pathFile;
};

class Graphics
{
public:
	Graphics();
	virtual ~Graphics();
	static void sinAnimation(double limit, Texture* texture);
	static void render(SDL_Rect* source, SDL_Rect* destiny, Texture* texture);

private:
	static void setAlphaModulation(Uint8 alpha, Texture* texture);
	static void setBlendMode(SDL_BlendMode mode, Texture* texture);
};
