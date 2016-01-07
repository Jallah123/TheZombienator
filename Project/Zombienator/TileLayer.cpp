#include "TileLayer.h"
#include "Map.h"
#include "TileSet.h"
#include <limits>
#include <iostream>

TileLayer::TileLayer() : Layer()
{
}

TileLayer::TileLayer(Map * map) : Layer(map)
{
	tileSet = map->GetTileSets().at(0);
}


TileLayer::~TileLayer()
{
}

void TileLayer::Draw(SDL_Renderer& ren, int XOffset, int YOffset)
{
	//Get Tileset rect
	
	SDL_Rect src = { 0,0,tileSet->TileWidth(),tileSet->TileHeight() };
	
	int x, y;
	for (y = 0; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			size_t gid = tilesIDs.at(y*width + x);
			if (gid < INT_MAX) {
				src.x = x * tileSet->TileWidth() + XOffset;
				src.y = y * tileSet->TileHeight() + YOffset;
				SDL_Rect* r = tileSet->GetTile(gid);
				DrawRect(r, tileSet->Texture(), &src, ren);
			}
		}
	}
}

void TileLayer::AddTileID(size_t id)
{
	tilesIDs.push_back(id);
}
