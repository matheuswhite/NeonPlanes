#include "Texture.h"

//temporary. delete after
Texture::Texture(std::string pathFile)
{
	this->pathFile = pathFile;
	this->texture = nullptr;

	this->loadFromFile(Game::getRenderer());
}

Texture::~Texture()
{
	this->free();
}

void Texture::loadFromFile(SDL_Renderer* renderer) {
	this->free();

	
	SDL_Surface* loadedSurface = IMG_Load(this->pathFile.c_str());

	if (loadedSurface == nullptr) {
		std::cerr << "Error in loadFromFile. Line: " << __LINE__ << std::endl;
	}
		
	this->texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

	if (this->texture == nullptr) {
		std::cerr << "Error in loadFromFile. Line: " << __LINE__ << std::endl;
	}

	SDL_FreeSurface(loadedSurface);
	loadedSurface = nullptr;
}

/*
void Texture::render(SDL_Rect* source, SDL_Rect* destiny, SDL_Renderer* render) {
	SDL_RenderCopy(render, this->texture, source, destiny);
}
*/

void Texture::free() {
	if (this->texture != nullptr) {
		SDL_DestroyTexture(this->texture);
	}
}

SDL_Texture* Texture::getTexture() const {
	return this->texture;
}

/*
void Texture::setBlendMode(SDL_BlendMode blending) {
	SDL_SetTextureBlendMode(this->texture, blending);
}

void Texture::setAlphaModulation(Uint8 alpha) {
	SDL_SetTextureAlphaMod(this->texture, alpha);
}

	if (object->lastPosition != position) {
		object->frame = 0;
	}

	object->row = position;


	Vector2D center(object->Width/2 * object->getFrame(), object->Height/2 * object->getRow());
	Vector2D half(object->Width/2, object->Height/2);
	Rectangle rect(&center, &half);

	object->frame++;

	object->source = &rect;

	this->renderGameObject(object, renderer);
*/