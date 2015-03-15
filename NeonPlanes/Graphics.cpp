#include "Graphics.h"

Graphics::Graphics() {
}

Graphics::~Graphics() {
}

void Graphics::sinAnimation(double limit, Texture* texture) {
	double current = 0;
	const double pass = 0.1;

	while (current < limit) {
		if (current > limit/2 - 0.1 && current < limit/2 + 0.2) {
			SDL_Delay(750);
		}

		SDL_RenderClear(Game::getRenderer());

		setBlendMode(SDL_BLENDMODE_BLEND, texture);
		setAlphaModulation(sin(current) * 255, texture);
		render(nullptr,nullptr,texture);

		SDL_RenderPresent(Game::getRenderer());

		current += pass;
		SDL_Delay(100);
	}
	
	delete texture;
	SDL_RenderClear(Game::getRenderer());
	SDL_RenderPresent(Game::getRenderer());
}

void Graphics::render(SDL_Rect* source, SDL_Rect* destiny, Texture* texture) {
	SDL_RenderCopy(Game::getRenderer(), texture->getTexture(), source, destiny);
}

void Graphics::setAlphaModulation(Uint8 alpha, Texture* texture) {
	SDL_GetTextureAlphaMod(texture->getTexture(), &alpha);
}

void Graphics::setBlendMode(SDL_BlendMode mode, Texture* texture) {
	SDL_SetTextureBlendMode(texture->getTexture(), mode);
}


//Texture
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

void Texture::free() {
	if (this->texture != nullptr) {
		SDL_DestroyTexture(this->texture);
	}
}

SDL_Texture* Texture::getTexture() const {
	return this->texture;
}

/*
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