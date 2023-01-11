#pragma once
#include "Game.h"


class ImgM{
public:
	static SDL_Texture* LoadI(const char* filename);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst);
};