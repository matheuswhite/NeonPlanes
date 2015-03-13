#pragma once

#include "core.h"
#include "Vector2D.h"

//temporary. delete after
class Texture
{
public:
	Texture(std::string pathFile);
	virtual ~Texture();

	void loadFromFile(SDL_Renderer* renderer);
	void setBlendMode(SDL_BlendMode blending);
	void setAlphaModulation(Uint8 alpha);
	void render(SDL_Rect* source, SDL_Rect* destiny, SDL_Renderer* renderer);
	void renderSource();
	void free();

	int getWidth() const;
	int getHeight() const;
	SDL_Texture* getTexture() const;

private:
	SDL_Texture* texture;

	std::string pathFile;

	int width;
	int height;
};
