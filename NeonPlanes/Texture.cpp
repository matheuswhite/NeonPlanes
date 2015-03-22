#include "Texture.h"

Texture::Texture()
{
	this->texture = nullptr;
}

Texture::~Texture()
{
	this->free();
}

void Texture::loadImage(SDL_Renderer* renderer, std::string pathFile) {
	this->free();

	SDL_Surface* surface = IMG_Load(pathFile.c_str());

	if (surface == nullptr) {
		std::cerr << "Error in loadFromFile. Line: " << __LINE__ << std::endl;
		return;
	}

	this->texture = SDL_CreateTextureFromSurface(renderer, surface);

	if (this->texture == nullptr) {
		std::cerr << "Error in loadFromFile. Line: " << __LINE__ << std::endl;
		return;
	}

	SDL_FreeSurface(surface);
	surface = nullptr;
}

void Texture::loadTTF(SDL_Renderer* renderer, Font* font) {
	TTF_Font* font_temp = TTF_OpenFont(font->getFont().c_str(), font->getSize());

	if (font_temp == nullptr) {
		std::cerr << "Cannot open font! Line: " << __LINE__ << std::endl;
		return;
	}

	SDL_Surface* surface = TTF_RenderText_Solid(font_temp, font->getValue().c_str(), font->getColor());

	if (surface == nullptr) {
		std::cerr << "Error in loadFromFile. Line: " << __LINE__ << std::endl;
		return;
	}

	this->texture = SDL_CreateTextureFromSurface(renderer, surface);

	if (this->texture == nullptr) {
		std::cerr << "Error in loadFromFile. Line: " << __LINE__ << std::endl;
		return;
	}

	SDL_FreeSurface(surface);
	surface = nullptr;

	std::cerr << "Loaded !" << std::endl;
}

void Texture::free() {
	if (this->texture != nullptr) {
		SDL_DestroyTexture(this->texture);
	}
}

SDL_Texture* Texture::getTexture() const {
	return this->texture;
}