#include "Game.h"

SDL_Window* Game::window = nullptr;
SDL_Renderer* Game::renderer = nullptr;
World* Game::world = nullptr;

std::vector<System*> Game::systems;
std::map<std::string, System*> Game::map_systems;

const int Game::SCREEN_WIDTH = 640;
const int Game::SCREEN_HEIGHT = 480;

Game::Game(std::string name, int windows_x, int windows_y, int flag)
{
	
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		std::cerr << "Error in Game constructor. Line: " << __LINE__ << std::endl;

	this->window = SDL_CreateWindow(name.c_str(), windows_x, windows_y, Game::SCREEN_WIDTH, Game::SCREEN_HEIGHT, flag);
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
	this->addSystem(new CheckCollision());
	this->addSystem(new Graphics());
	this->addSystem(new DataStore());
	this->addSystem(new ObjectManager());
	this->addSystem(new Texts());

	((Graphics*)this->getSystem("Graphics"))->sinAnimation(M_PI, new Texture(utility::IMAGE_PATH +"Logo.png"));

	SDL_Event e;
	while (SDL_PollEvent(&e) != 0){}
}

void Game::draw() {
	for each (auto object in World::getCurrentPackage()->getGameObjects()) {
		auto obj = dynamic_cast<Sprite*>(object);
		obj->draw();
	}
}

//improvisado
void Game::update() {
	for each (auto object in World::getCurrentPackage()->getGameObjects()) {
		auto obj = dynamic_cast<Behavior*>(object);
		obj->run();
	}
}

//improvisado
bool Game::handlingEvents() {
	SDL_Event e;
	World::switchGameState(new PlayState());
	World::switchPackage(typeid(PlayPackage).name());

	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		else if (e.type == SDL_KEYDOWN) {
			switch (e.key.keysym.sym) {
			case SDLK_ESCAPE:
				return false;
			case SDLK_SPACE:
				World::getCurrentState()->execute_X();
				break;
			case SDLK_a:
				World::getCurrentState()->execute_A();
				break;
			case SDLK_s:
				World::getCurrentState()->execute_B();
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

	for each (System* var in this->systems)
	{
		delete var;
		var = nullptr;
	}
	this->systems.clear();

	SDL_Quit();
}


SDL_Window* Game::getWindow() {
	return window;
}

SDL_Renderer* Game::getRenderer() {
	return renderer;
}

std::vector<System*> Game::getListSystems() {
	return systems;
}

bool Game::addSystem(System* system) {
	for each (System* var in systems) {
		if (var == system) {
			return false;
		}
	}

	systems.push_back(system);
	map_systems.insert(GAME_PAIR(typeid(*system).name(), system));
	return true;
}

System* Game::getSystem(std::string system) {
	return map_systems[system]; 
}