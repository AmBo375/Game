#pragma once
#include "Vector2F.h"
#include "ECS.h"

class TransComp : public Comp{
public:
	Vector2F pos;
	Vector2F speed;
	int show = 2;

	int h = 32;
	int w = 32;
	int sc = 1;
	TransComp() {
	}
	TransComp(float x, float y) {
		pos.x = x;
		pos.y = y;
	}
	TransComp(float x, float y, int height, int width, int scale) {
		pos.x = x;
		pos.y = y;
		h = height;
		w = width;
		sc = scale;
	}
	void init() override {
		speed.x = 0;
		speed.y = 0;
	}
	void update() override {
		pos.x += static_cast<int>(speed.x * show);
		pos.y += static_cast<int>(speed.y * show);
	}
};