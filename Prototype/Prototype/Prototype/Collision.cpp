#include "CollisionComp.h"

bool Collision::interSec(const SDL_Rect& rctA, const SDL_Rect& rctB) {
	if (rctA.x + rctA.w >= rctB.x && rctB.x + rctB.w >= rctA.x && rctA.y + rctA.h >= rctB.y && rctB.y + rctB.h >= rctA.y) return true;
	return false;
}
