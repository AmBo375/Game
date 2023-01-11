#include "Map.h"

int lvl1[10][18] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

Map::Map() {
	ground = ImgM::LoadI("ground.jpg");

	LoadM(lvl1);
	src.h = 32;
	src.w = 32;
	src.x = 0;
	src.y = 0;

	dst.h = 2 * src.h;
	dst.w = 2 * src.w;
}
Map::~Map()
{
	SDL_DestroyTexture(ground);
}
void Map::LoadM(int arr[10][18]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 18; j++) {
			map[i][j] = arr[i][j];
		}
	}
}
void Map::DrawM() {
	int type = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 18; j++) {
			type = map[i][j];

			dst.x = i * 32;
			dst.y = j * 32;

			switch (type) {
			case 0:
				ImgM::Draw(ground, src, dst);
				break;
			case 1:

			default:
				break;
			}
		}
	}

}