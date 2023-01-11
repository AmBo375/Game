#pragma once
#include "GameObj.h"

class Map {
public:
	Map();
	~Map();
	void LoadM(int arr[10][18]);
	void DrawM();

private:
	SDL_Rect src{}, dst{};
	SDL_Texture* ground=nullptr;
	int map[20][25];
};