#include "ObjectLayer.h"



ObjectLayer::ObjectLayer() : Layer()
{
}


ObjectLayer::~ObjectLayer()
{
}

void ObjectLayer::Draw(SDL_Renderer & ren)
{
	size_t x, y;
	for (auto& r : rects) {
		DrawRect(r, ren);
	}
}
