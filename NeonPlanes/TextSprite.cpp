#include "TextSprite.h"

TextSprite::TextSprite(Rectangle* destiny, std::string value, std::string font, Uint8 size, const SDL_Color& color) : Sprite(destiny)
{
	TTF_Font* font_temp = TTF_OpenFont(font.c_str(), size);
	
	if (font_temp != nullptr) 
	{
		SDL_Surface* temp = TTF_RenderText_Solid(font_temp, value.c_str(), color);

		this->texture = new Texture(temp);

		SDL_FreeSurface(temp);
		temp = nullptr;
	}
	else {
		std::cerr << "Cannot open font! Line: " << __LINE__ << std::endl;
	}
}

TextSprite::~TextSprite()
{
}

void TextSprite::draw() {
	Graphics::render(nullptr, destiny->getRectSDL(), this->texture);
}