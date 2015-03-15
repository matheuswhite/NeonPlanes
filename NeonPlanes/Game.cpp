#include "Game.h"

SDL_Renderer* Game::renderer = nullptr;
World* Game::world = nullptr;

Game::Game(std::string name, int windows_x, int windows_y, int flag)
{
	this->init = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cerr << "Error in Game constructor. Line: " << __LINE__ << std::endl;
		this->init = false;
	}

	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		std::cerr << "Error in Game constructor. Line: " << __LINE__ << std::endl;
		this->init = false;
	}

	if (TTF_Init() < 0)
	{
		std::cerr << "Error in Game constructor. Line: " << __LINE__ << std::endl;
		this->init = false;
	}

	this->window = SDL_CreateWindow(name.c_str(), windows_x, windows_y, SCREEN_WIDTH, SCREEN_HEIGHT, flag);
	if (this->window == nullptr)
	{
		std::cerr << "Error in Game constructor. Line: " << __LINE__ << std::endl;
		this->init = false;
	}

	this->renderer = SDL_CreateRenderer(this->window, -1, 0);
	if (this->renderer == nullptr)
	{
		std::cerr << "Error in Game constructor. Line: " << __LINE__ << std::endl;
		this->init = false;
	}
}

bool Game::isInitialize() const {
	return this->init;
}

Game::~Game()
{
	this->clear();
}


bool Game::initialize() {
	this->world = new World();

	if (this->world == nullptr) {
		std::cerr << "Error in Game constructor. Line: " << __LINE__ << std::endl;
		return false;
	}

#if _DEBUG
	//Debug Mode
	SDL_SetRenderDrawColor(Game::getRenderer(), 0, 255, 255, 255);
	World::switchGameState("class DebugState");

#else
	//Release Mode
	SDL_SetRenderDrawColor(Game::getRenderer(), 255, 255, 255, 255);
	World::switchGameState("class MainMenu");

#endif // !_DEBUG

	SDL_RenderClear(Game::renderer);
	SDL_RenderPresent(Game::renderer);

	//Graphics::sinAnimation(M_PI, new Texture(IMAGE_PATH + "Logo.png"));

	SDL_Event e;
	while (SDL_PollEvent(&e) != 0){}

	return true;
}

void Game::draw() {
	SDL_RenderClear(Game::getRenderer());

	for each (auto layer in World::getCurrentState()->getLayers()) 
	{
		for each (auto object in layer->getGameObjects()) 
		{
			auto obj = dynamic_cast<Sprite*>(object);
			obj->draw();
		}
	}

	SDL_RenderPresent(Game::getRenderer());
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
		switch (e.type) {
		case SDL_QUIT:
			return false;
		case SDL_KEYDOWN:
			switch (e.key.keysym.sym) {
			case SDLK_ESCAPE:
#if _DEBUG
				return false;
#else
				World::getCurrentState()->execute_BTN_ENTER();
#endif
				break;
			case SDLK_SPACE:
				World::getCurrentState()->execute_BTN_SPACE();
				break;
			case SDLK_z:
				World::getCurrentState()->execute_BTN_Z();
				break;
			case SDLK_KP_ENTER:
				World::getCurrentState()->execute_BTN_ENTER();
				break;
			case SDLK_UP:
				World::getCurrentState()->execute_UP();
				break;
			case SDLK_DOWN:
				World::getCurrentState()->execute_DOWN();
				break;
			case SDLK_LEFT:
				World::getCurrentState()->execute_LEFT();
				break;
			case SDLK_RIGHT:
				World::getCurrentState()->execute_RIGHT();
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			if (typeid(*World::getCurrentState()) == typeid(DebugState)) {
				Command::stop();
			}
			break;
		default:
			break;
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

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}


SDL_Window* Game::getWindow() {
	return window;
}

SDL_Renderer* Game::getRenderer() {
	return renderer;
}
