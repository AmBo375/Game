#include "InputEv.h"

void KeyMngr::Kprs(SDL_Keysym key){

}

void KeyMngr::Krls(SDL_Keysym key){



void MouseMngr::Mprs(Uint8 button){
	if (Game::event.type == SDL_MOUSEBUTTONDOWN){
		switch (button){
		case SDL_BUTTON_LEFT:
			break;
		default:
			break;
		}
	}
}

void MouseMngr::Mrls(Uint8 button){
	if (Game::event.type == SDL_MOUSEBUTTONUP){
		switch (button){
		case SDL_BUTTON_LEFT:
			break;
		default:
			break;
		}
	}
}

void MouseMngr::Mmove(){
	if (Game::event.type==SDL_MOUSEMOTION){
	}
}