#pragma once
#include "Layer.h"
#include "Map.h"
#include "TileSet.h"
Layer::Layer()
{
}

Layer::Layer(Map * map) : map(map)
{
}


Layer::~Layer()
{
}


void Layer::DrawRect(SDL_Rect* srcRect, SDL_Texture* texture, SDL_Rect* destRect, SDL_Renderer& ren)
{
	SDL_RenderCopy(&ren, texture, srcRect, destRect);
}

void Layer::DrawRect(SDL_Rect* rect, SDL_Renderer& ren)
{
	SDL_SetRenderDrawColor(&ren, 255, 0, 0, 255);
	SDL_RenderDrawRect(&ren, rect);
}
