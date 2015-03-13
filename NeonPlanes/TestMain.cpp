#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

//C:\Users\Matheus\Documents\Codigos\Cplusplus\NeonPlanes\Debug\Images

#ifndef _DEBUG
std::string IMAGE_PATH = "Images\\";
#else
std::string IMAGE_PATH = "..\\Debug\\Images\\";
#endif // !_DEBUG


int main1(int argc, char** argv) {
	bool quit = false;

	SDL_Event event;

	IMAGE_PATH.append("pict3159.jpg");

	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_JPG);

	SDL_Window * window = SDL_CreateWindow("SDL2 Displaying Image",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Surface * image = IMG_Load(IMAGE_PATH.c_str());
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);

	while (!quit) {
		SDL_WaitEvent(&event);

		switch (event.type) {
		case SDL_QUIT:
			quit = true;
			break;
		}

		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();

	return 0;
}