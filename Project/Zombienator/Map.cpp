#pragma once
#include "Map.h"
#include "MapParser.h"

using std::string;

Map::Map(char* p, SDL_Renderer& ren) : path(p), renderer(&ren)
{	
	this->parser = new MapParser(this);
}

Map::~Map()
{
	std::vector<TileSet*>::reverse_iterator its;
	for (its = tilesets.rbegin(); its != tilesets.rend(); ++its)
		delete *its;

	tilesets.clear();

	std::vector<SDL_Rect*>::reverse_iterator it;
	for (it = rects.rbegin(); it != rects.rend(); ++it)
		delete *it;

	rects.clear();


	delete parser;
}

void Map::Size(int w, int h)
{
	this->width = w; 
	this->height = h;

	int x, y;
	for (y = 0; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			int pX = x * tileWidth;
			int pY = y* tileHeight;
			rects.push_back(new SDL_Rect{ pX,pY, tileWidth, tileHeight });
		}
	}
}

void Map::AddTileset(TileSet* ts)
{
	ts->Load(*renderer);
	tilesets.push_back(ts);
}

void Map::Draw(SDL_Renderer & ren, int XOffset, int YOffset)
{
	for (const auto& l : backLayers) {
		l.second->Draw(ren, XOffset, YOffset);//Render each layer
	}
}

void Map::DrawFrontLayer(SDL_Renderer& ren, int XOffset, int YOffset)
{
	for (const auto& l : frontLayers) {
		l.second->Draw(ren, XOffset, YOffset);//Render each layer
	}
}

ObjectLayer * Map::GetObjectLayer(string key)
{
	return dynamic_cast<ObjectLayer*>(this->backLayers.at(key));
}
