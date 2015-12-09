#pragma once
#include "Map.h"
#include "MapParser.h"
#include "TileLayer.h"
#include "ObjectLayer.h"

using std::string;

Map::Map(string p) : path(p)
{
	this->parser = new MapParser(this);
	bounds = { 0, 0, tileWidth * width, tileHeight * height };
	GenerateGraph();
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
			int pY = y * tileHeight;
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
		TileLayer* layer = dynamic_cast<TileLayer*>(l.second);
		if (layer != nullptr) {
			layer->Draw(ren, XOffset, YOffset);
		}
	}
}

ObjectLayer* Map::GetObjectLayer(string key)
{
	return dynamic_cast<ObjectLayer*>(this->backLayers.at(key));
}

void Map::GenerateGraph()
{
	if (backLayers["Waypoints"] == nullptr) 
	{
		return;
	}
	ObjectLayer* waypointsLayer = GetObjectLayer("Waypoints");
	if (waypointsLayer == nullptr)
	{
		return;
	}
	vector<SDL_Rect*> waypoints = waypointsLayer->GetRects();
	for (int i = 0; i < waypoints.size(); i++)
	{
		SDL_Rect waypoint1 = *waypoints.at(i);
		for (int ii = 0; ii < waypoints.size(); ii++)
		{
			SDL_Rect waypoint2 = *waypoints.at(ii);
			if (find(nodes[waypoints.at(i)].begin(), nodes[waypoints.at(i)].end(), waypoints.at(ii)) == nodes[waypoints.at(i)].end() && !IntersectsWithCollisionLayer(waypoint1, waypoint2))
			{
				nodes[waypoints.at(i)].push_back(waypoints.at(ii));
			}
		}
	}
}

bool Map::IntersectsWithCollisionLayer(SDL_Rect wp1, SDL_Rect wp2)
{
	vector<SDL_Rect*> collision = GetObjectLayer("Collision")->GetRects();
	bool intersect = false;
	for (SDL_Rect* collisionObject : collision)
	{
		if (SDL_IntersectRectAndLine(collisionObject, &wp1.x, &wp1.y, &wp2.x, &wp2.y))
		{
			intersect = true;
			break;
		}
	}
	return intersect;
}