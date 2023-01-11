#pragma once
#include "InputEv.h"


class GameObj {
public:
	GameObj(const char* texS, int x, int y);
	~GameObj();
	void update();
	void render();
	void clean();

	bool running() {
		return isRunning;
	};
private:
	int xpos=0, ypos=0;
	bool isRunning = false;
	SDL_Texture* objT = NULL;
	SDL_Rect srcR{};
	SDL_Rect dstR{};
};
