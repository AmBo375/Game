#pragma once
#include "SprComp.h"

class KeyMngr :public Comp {
public:
	TransComp* Transform;

	void init() override{
		Transform= &entity->GetComp<TransComp>();
	}
	void update() override {
		if (Game::event.type == SDL_KEYDOWN) {
			switch (Game::event.key.keysym.sym) {
			case SDLK_w:
				Transform->speed.y = -1;
				break;
			case SDLK_s:
				Transform->speed.y = 1;
				break;
			case SDLK_q:
				Transform->speed.x = -1;
				break;
			case SDLK_d:
				Transform->speed.x = 1;
				break;
			case SDLK_i:
				break;
			case SDLK_j:
				break;
			case SDLK_k:
				break;
			case SDLK_l:
				break;
			default:
				break;
			}
		}
		if (Game::event.type == SDL_KEYUP) {
			switch (Game::event.key.keysym.sym) {
			case SDLK_w:
				Transform->speed.y = 0;
				break;
			case SDLK_s:
				Transform->speed.y = 0;
				break;
			case SDLK_q:
				Transform->speed.x = 0;
				break;
			case SDLK_d:
				Transform->speed.x = 0;
				break;
			case SDLK_i:
				break;
			case SDLK_j:
				break;
			case SDLK_k:
				break;
			case SDLK_l:
				break;
			case SDLK_ESCAPE:
				SDL_Quit();
				break;
			default:
				break;
			}
		}
	}
};

struct MouseMngr {
	void Mprs(Uint8 button);
	void Mrls(Uint8 button);
	void Mmove();
};