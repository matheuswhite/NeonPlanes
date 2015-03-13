#include "Game.h"

SDL_Renderer* Game::renderer = nullptr;
World* Game::world = nullptr;

Game::Game(std::string name, int windows_x, int windows_y, int flag)
{
	
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		std::cerr << "Error in Game constructor. Line: " << __LINE__ << std::endl;

	this->window = SDL_CreateWindow(name.c_str(), windows_x, windows_y, SCREEN_WIDTH, SCREEN_HEIGHT, flag);
	if (this->window == nullptr)
		std::cerr << "Error in Game constructor. Line: " << __LINE__ << std::endl;

	this->renderer = SDL_CreateRenderer(this->window, -1, 0);
	if (this->renderer == nullptr)
		std::cerr << "Error in Game constructor. Line: " << __LINE__ << std::endl;
	
	this->world = new World();
	if (this->world == nullptr)
		std::cerr << "Error in Game constructor. Line: " << __LINE__ << std::endl;

	SDL_SetRenderDrawColor(Game::getRenderer(), 255, 255, 255, 255);
	SDL_RenderClear(Game::renderer);
	SDL_RenderPresent(Game::renderer);
}

Game::~Game()
{
	this->clear();
}


void Game::init() {
#if _DEBUG
	//Debug Mode

	World::switchGameState("DebugState");

#else
	//Release Mode

	World::switchGameState("MainMenu");

#endif // !_DEBUG

	Graphics::sinAnimation(M_PI, new Texture(IMAGE_PATH + "Logo.png"));

	SDL_Event e;
	while (SDL_PollEvent(&e) != 0){}
}

void Game::draw() {
	for each (auto layer in World::getCurrentState()->getLayers()) 
	{
		for each (auto object in layer->getGameObjects()) 
		{
			auto obj = dynamic_cast<Sprite*>(object);
			obj->draw();
		}
	}
}

//improvisado
void Game::update() {




	for each (auto layer in World::getCurrentState()->getLayers())
	{
		for each (auto object in layer->getGameObjects())
		{
			auto obj = dynamic_cast<Behavior*>(object);
			obj->run();
		}
	}




}

//improvisado
bool Game::handlingEvents() {
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		else if (e.type == SDL_KEYDOWN) {
			switch (e.key.keysym.sym) {
			case SDLK_ESCAPE:
#if _DEBUG
	return false;
#else
	World::getCurrentState()->execute_BTN3;
#endif
			case SDLK_SPACE:
				World::getCurrentState()->execute_BTN_SPACE;
				break;
			case SDLK_z:
				World::getCurrentState()->execute_BTN_Z;
				break;
			case SDLK_KP_ENTER:
				World::getCurrentState()->execute_BTN_ENTER;
				break;
			case SDLK_UP:
				World::getCurrentState()->execute_UP;
				break;
			case SDLK_DOWN:
				World::getCurrentState()->execute_DOWN;
				break;
			case SDLK_LEFT:
				World::getCurrentState()->execute_LEFT;
				break;
			case SDLK_RIGHT:
				World::getCurrentState()->execute_RIGHT;
				break;
			default:
				break;
			}
		}
	}

	return true;
}

void Game::clear() {
	delete this->world;
	this->world = nullptr;
	
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	this->window = nullptr;
	this->renderer = nullptr;

	SDL_Quit();
}


SDL_Window* Game::getWindow() {
	return window;
}

SDL_Renderer* Game::getRenderer() {
	return renderer;
}
