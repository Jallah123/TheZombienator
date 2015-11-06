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

void Map::Draw(SDL_Renderer & ren)
{
	for (const auto& l : layers) {

		l.second->Draw(ren);//Render each layer
	}
}
/*

bool Map::checkCollision(int _x, int _y, int _width, int _height) {
	
	SDL_Rect unitRectangle = { _x, _y, _width, _height };

	for (int j = collisionLayers.size() - 1; j >= 0; j--)
	{
		vector<CollisionObject> collisionObjects = collisionLayers[j].getCollisionObjects();

		for (int k = collisionObjects.size() - 1; k >= 0; k--)
		{
			SDL_Rect collisionRectangle = { 
				collisionObjects[k].getX(),
				collisionObjects[k].getY(),
				collisionObjects[k].getWidth(),
				collisionObjects[k].getHeight()
			};

			if (SDL_HasIntersection(&unitRectangle, &collisionRectangle)) {
				return true;
			}
		}
	}
	return false;
}

*/