#include "Game.h"

Game* game;

int main(int argc, char* argv[]) {
	const int fps = 60;
	const int fd = 1000 / fps;
	int fs, ft;
	game = new Game();
	game->init("Game", "Cult of The Lamb.png",  800, 600, false);
	while (game->running()) {
		fs = SDL_GetTicks();
		game->HandleEvents();
		game->update();
		game->render();
		ft = SDL_GetTicks() - fs;
		if (fd > ft) {
			SDL_Delay(fd - ft);
		}
	}
	game->clean();
	return 0;
}