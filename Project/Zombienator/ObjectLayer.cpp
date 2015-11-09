#include "ObjectLayer.h"



ObjectLayer::ObjectLayer() : Layer()
{
}


ObjectLayer::~ObjectLayer()
{
	std::vector<SDL_Rect*>::reverse_iterator it;
	for (it = rects.rbegin(); it != rects.rend(); ++it)
		delete *it;

	rects.clear();
}

void ObjectLayer::Draw(SDL_Renderer & ren)
{
	size_t x, y;
	for (auto& r : rects) {
		DrawRect(r, ren);
	}
}

bool ObjectLayer::HasCollision(SDL_Rect src)
{
	for (const auto& r : rects) {
		if (SDL_HasIntersection(&src, r))
			return true;
	}
	return false;
}
