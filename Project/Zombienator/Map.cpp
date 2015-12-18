#pragma once
#include "Map.h"
#include "MapParser.h"
#include "TileLayer.h"
#include "ObjectLayer.h"
#include <limits>

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
		graph.AddNode(new Node(i, waypoints.at(i)->x, waypoints.at(i)->y));
	}

	for (auto& node1 : graph.GetNodes())
	{
		for (auto& node2 : graph.GetNodes())
		{
			if (!IntersectsWithCollisionLayer(node1->getDestRect(), node2->getDestRect()) && !ExistsInMap(node1, node2))
			{
				node1->AddEdge(node2);
				node2->AddEdge(node1);
				graph.AddEdge(node1, node2);
				graph.AddEdge(node2, node1);
			}
		}
	}
}

bool Map::ExistsInMap(Node* n1, Node* n2)
{
	for (auto& a : n1->Adjacent())
	{
		if (n1 == n2)
		{
			return true;
		}
	}
	return false;
}

bool Map::IntersectsWithCollisionLayer(SDL_Rect wp1, SDL_Rect wp2)
{
	vector<SDL_Rect*> collision = GetObjectLayer("Collision")->GetRects();
	bool intersect = false;
	for (SDL_Rect*
		collisionObject : collision)
	{
		SDL_Rect collisionObjectWithBox{ collisionObject->x - 10, collisionObject->y - 10, collisionObject->w + 20, collisionObject->h + 20 };
		if (SDL_IntersectRectAndLine(&collisionObjectWithBox, &wp1.x, &wp1.y, &wp2.x, &wp2.y))
		{
			intersect = true;
			break;
		}
	}
	return intersect;
}