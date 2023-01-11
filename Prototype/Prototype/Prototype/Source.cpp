#include "CollisionComp.h"
#include "GameObj.h"
#include "Map.h"
#include "InputEv.h"

using namespace std;


SDL_Renderer* Game::renderer = nullptr;
//Map* map;
Mngr Manager;
auto& Player(Manager.AddEnt());
auto& Wall(Manager.AddEnt());

SDL_Texture* Background;
SDL_Surface* Icon;
SDL_Event Game::event;

Game::Game() {}
Game::~Game() {}



void Game::init(const char* title, const char* icon, int width, int height, bool fullscreen){
	int flags = 0;
	Icon = IMG_Load(icon);
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		cout << "Subsystem Initialized..." << endl;
	if (renderer) & (window); {
			SDL_CreateWindowAndRenderer(width, height, flags, &window, &renderer);
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "Window and Renderer created!" << endl;
			SDL_SetWindowIcon(window, Icon);
			SDL_SetWindowTitle(window, title);
	}
		isRunning = true;

		//Background = ImgM::LoadI("Ra.png");
		//map = new Map();

		Player.AddComp<TransComp>(60.0f ,50.0f ,32 ,32 , 2);
		Player.AddComp<SprComp>("ground.jpg");
		Player.AddComp<KeyMngr>();
		Player.AddComp<ColliderComp>("player");

		Wall.AddComp<TransComp>(30.0f, 10.0f, 32, 32, 1);
		Wall.AddComp<SprComp>("ground.jpg");
		Wall.AddComp<ColliderComp>("walls");
	}
	else {
		isRunning = false;
	}
}
void Game::HandleEvents() {
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
		}

}
void Game::update() {
	Manager.update();
	if (Collision::interSec(Player.GetComp<ColliderComp>().Collider, Wall.GetComp<ColliderComp>().Collider)) {
		Player.GetComp<TransComp>().sc = 2;
		cout << "Wall Hit!" << endl;
	}
	cout << Player.GetComp<TransComp>().pos.x << endl;
}
void Game::render() {
	SDL_RenderClear(renderer);
	//map->DrawM();
	Manager.init();
	Manager.draw();
	SDL_RenderPresent(renderer);
}
void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game Created!" << endl;
}