#include "GameObj.h"


GameObj::GameObj(const char* path, int x, int y) {
	objT = ImgM::LoadI(path);
	xpos = x;
	ypos = y;
}
GameObj::~GameObj()
{
}
void GameObj::update() {
	srcR.h = 32;
	srcR.w = 32;
	srcR.x = 0;
	srcR.y = 0;

	dstR.h = 2 * srcR.h;
	dstR.w = 2 * srcR.w;
	dstR.x = xpos;
	dstR.y = ypos;
}
void GameObj::render() {
	SDL_RenderCopy(Game::renderer, objT, &srcR, &dstR);
}

void GameObj::clean()
{

}