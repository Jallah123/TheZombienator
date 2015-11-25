#pragma once
#include "Map.h"
#include "MapParser.h"
#include "TileLayer.h"
#include "ObjectLayer.h"

using std::string;

Map::Map(string p, SDL_Renderer& ren) : path(p), renderer(&ren)
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

	// Only draw TileLayers
	for (auto& l : layers) {
		TileLayer* layer = dynamic_cast<TileLayer*>(l.second);
		if (layer != nullptr) {
			layer->Draw(ren, XOffset, YOffset);
		}
	}

	// For objectlayer debugging
	/*
	for (auto& l : layers) {
		ObjectLayer* layer = dynamic_cast<ObjectLayer*>(l.second);
		if (layer != nullptr) {
			layer->Draw(ren, XOffset, YOffset);
		}
	}
	*/
}

ObjectLayer * Map::GetObjectLayer(string key)
{
	return dynamic_cast<ObjectLayer*>(this->layers.at(key));
}
