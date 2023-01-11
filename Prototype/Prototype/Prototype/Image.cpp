#include "Image.h"

SDL_Texture* ImgM::LoadI(const char* filename)
{
    SDL_Surface* tmpS = IMG_Load(filename);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpS);
    SDL_FreeSurface(tmpS);

    return tex;
}

void ImgM::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst) {
    SDL_RenderCopy(Game::renderer, tex, &src, &dst);
}