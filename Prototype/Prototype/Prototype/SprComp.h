#pragma once
#include "TransComp.h"
#include "Image.h"

class SprComp : public Comp{
private:
	TransComp* Transform;
	SDL_Texture* tex = nullptr;
	SDL_Rect srcR{}, dstR{};
public:
	SprComp()=default;
	SprComp(const char* filename) {
		tex = ImgM::LoadI(filename);
	}
	~SprComp() {
		SDL_DestroyTexture(tex);
	}
	void init() override {
		Transform = &entity->GetComp<TransComp>();
		srcR = { 0, 0, 32, 32 };
	}
	void update() override {
		dstR = { (int)Transform->pos.x,(int)Transform->pos.y,Transform->w * Transform->sc, Transform->h* Transform->sc };
	}
	void draw() override {
		ImgM::Draw(tex, srcR, dstR);
	}
};