#pragma once
#include "Game.h"
#include "TransComp.h"

class ColliderComp : public Comp {
public:
	SDL_Rect Collider;
	std::string tag;

	ColliderComp(std::string t) {
		tag = t;
	}
	TransComp* Transform;
	void init() override {
		if (!entity->hasComp<TransComp>()) { entity->AddComp<TransComp>(); }
		Transform = &entity->GetComp<TransComp>();
	}
	void update() override {
		Collider.x = static_cast <int>(Transform->pos.x);
		Collider.y = static_cast <int>(Transform->pos.y);
		Collider.w = Transform->w * Transform->sc;
		Collider.h = Transform->h * Transform->sc;
	}
};

class Collision {
public:
	static bool interSec(const SDL_Rect& rctA, const SDL_Rect& rctB);
};