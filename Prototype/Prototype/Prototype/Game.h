#pragma once
#ifndef Game_h
#define Game_h

#include "SDL.h"
#include <iostream>
#include <string>
#include "SDL_image.h"

class Game {
public:
	Game();
	~Game();

	void init(const char* title, const char* icon, int width, int height, bool fullscreen);
	void HandleEvents();
	void update();
	void render();
	void clean();
	static SDL_Renderer* renderer;
	static SDL_Event event;
	bool running() {
		return isRunning;
	};
private:
	int cnt = 0;
	bool isRunning = false;
	SDL_Window* window = nullptr;
};

#endif 