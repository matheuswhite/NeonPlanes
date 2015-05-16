#include "Game.h"

World *Game::gameWorld = nullptr;
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

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

	window = SDL_CreateWindow(name.c_str(), windows_x, windows_y, SCREEN_WIDTH, SCREEN_HEIGHT, flag);
	if (window == nullptr)
	{
		std::cerr << "Error in Game constructor. Line: " << __LINE__ << std::endl;
		this->init = false;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == nullptr)
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
	this->gameWorld = new World();

	if (this->gameWorld == nullptr) {
		std::cerr << "Error in Game constructor. Line: " << __LINE__ << std::endl;
		return false;
	}

#if _DEBUG
	//Debug Mode
	SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
	this->gameWorld->switchGameState(utility::MAIN_MENU);

#else
	//Release Mode
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	World::switchGameState(utility::MAIN_MENU);

#endif // !_DEBUG

	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	/*
	auto tex = new Texture();
	tex->loadImage(renderer, IMAGE_PATH + "Logo.png");
	Graphics::sinAnimation(M_PI, tex->getTexture());*/

	this->shootState = false;
	this->lightState = false;
	this->upState = false;
	this->downState = false;
	this->leftState = false;
	this->rightState = false;

	SDL_Event e;
	while (SDL_PollEvent(&e) != 0){}

	return true;
}

void Game::draw() {
	
	SDL_RenderClear(renderer);

	for each (auto layer in this->gameWorld->getCurrentState()->getVectorLayers()) 
	{
		for each (auto object in layer->getGameObjects()) 
		{
			if (object->isActive()) {
				for each (auto sprite in object->getVectorSprites())
				{
					if (sprite->isActive())
						sprite->draw();
				}
			}
		}
	}

	SDL_RenderPresent(renderer);
}

//improvisado
void Game::update() {



	
	for each (auto layer in this->gameWorld->getCurrentState()->getVectorLayers())
	{
		layer->addPending();
		for each (auto object in layer->getGameObjects())
		{
			if (object->isActive()) {
				for each (auto behavior in object->getVectorBaheviors())
				{
					if (behavior->isActive())
						behavior->run();
				}
			}
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
			if (typeid(*this->gameWorld->getCurrentState()) == typeid(PlayState)) {
				if (e.key.keysym.sym == SDLK_SPACE) this->shootState = true;
				if (e.key.keysym.sym == SDLK_z) this->lightState = true;
				if (e.key.keysym.sym == SDLK_RETURN) this->gameWorld->getCurrentState()->execute_BTN_ENTER();
				if (e.key.keysym.sym == SDLK_UP) this->upState = true;
				if (e.key.keysym.sym == SDLK_DOWN) this->downState = true;
				if (e.key.keysym.sym == SDLK_LEFT) this->leftState = true;
				if (e.key.keysym.sym == SDLK_RIGHT) this->rightState = true;
			}
			else {
				switch (e.key.keysym.sym) {
				case SDLK_SPACE:
					this->gameWorld->getCurrentState()->execute_BTN_SPACE();
					break;
				case SDLK_z:
					this->gameWorld->getCurrentState()->execute_BTN_Z();
					break;
				case SDLK_RETURN:
					this->gameWorld->getCurrentState()->execute_BTN_ENTER();
					break;
				case SDLK_UP:
					this->gameWorld->getCurrentState()->execute_UP();
					break;
				case SDLK_DOWN:
					this->gameWorld->getCurrentState()->execute_DOWN();
					break;
				case SDLK_LEFT:
					this->gameWorld->getCurrentState()->execute_LEFT();
					break;
				case SDLK_RIGHT:
					this->gameWorld->getCurrentState()->execute_RIGHT();
					break;
				default:
					break;
				}
			}
			break;
		case SDL_KEYUP:
			if (typeid(*this->gameWorld->getCurrentState()) == typeid(PlayState)) {
				if (e.key.keysym.sym == SDLK_SPACE) this->shootState = false;
				if (e.key.keysym.sym == SDLK_z) this->lightState = false;
				if (e.key.keysym.sym == SDLK_UP) {
					this->upState = false;
					((PlayState*)this->gameWorld->getCurrentState())->stop();
				}
				if (e.key.keysym.sym == SDLK_DOWN) {
					this->downState = false;
					((PlayState*)this->gameWorld->getCurrentState())->stop();
				}
				if (e.key.keysym.sym == SDLK_LEFT) {
					this->leftState = false;
					((PlayState*)this->gameWorld->getCurrentState())->stop();
				}
				if (e.key.keysym.sym == SDLK_RIGHT) {
					this->rightState = false;
					((PlayState*)this->gameWorld->getCurrentState())->stop();
				}
			}
			break;
		default:
			break;
		}
	}

	if (this->getGameWorld()->isSwitchState()) {
		this->getGameWorld()->turnOffSwitchState();
	}
	else {
		if (typeid(*this->gameWorld->getCurrentState()) == typeid(PlayState)) {
			if (this->shootState) {
				this->gameWorld->getCurrentState()->execute_BTN_SPACE();
			}
			if (this->lightState) {
				this->gameWorld->getCurrentState()->execute_BTN_Z();
			}
			if (this->upState) {
				this->gameWorld->getCurrentState()->execute_UP();
			}
			if (this->downState) {
				this->gameWorld->getCurrentState()->execute_DOWN();
			}
			if (this->leftState) {
				this->gameWorld->getCurrentState()->execute_LEFT();
			}
			if (this->rightState) {
				this->gameWorld->getCurrentState()->execute_RIGHT();
			}
		}
	}
	

	return true;
}

void Game::clear() {
	delete this->gameWorld;
	this->gameWorld = nullptr;
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = nullptr;
	renderer = nullptr;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

World* Game::getGameWorld() {
	return gameWorld;
}