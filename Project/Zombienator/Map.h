#pragma once
#include <string>
#include <map>
#include <vector>
#include <SDL_rect.h>
#include <SDL_render.h>
#include "Layer.h"
#include "TileSet.h"
#include "ObjectLayer.h"
#include "Node.h"

using std::string;
using std::vector;

class MapParser;
class CollisionLayer;

class Map
{
private:
	std::string path = "";
	
	int width = 0;
	int height = 0;
	int tileWidth = 0;
	int tileHeight = 0;
	MapParser* parser = nullptr;
	SDL_Rect bounds = { 0,0,0,0 };

	std::map<string, Layer*> backLayers{};
	std::map<string, Layer*> frontLayers{};
	vector<TileSet*> tilesets{};
	vector<SDL_Rect*> rects{};
	SDL_Renderer* renderer;
public:
	Map(std::string path);
	~Map();

	std::string GetPath() const { return this->path; }
	void TileSize(int w, int h) { tileWidth = w; tileHeight = h; }
	void Size(int w, int h);

	int Width() { return width; }
	int Height() { return height; }

	int TileWidth() { return tileWidth; }
	int TileHeight() { return tileHeight; }

	void AddBackLayer(Layer* l) { backLayers.insert({ l->Name(), l }); }
	void AddFrontLayer(Layer* l) { frontLayers.insert({ l->Name(), l }); }

	void AddTileset(TileSet* ts);

	void Draw(SDL_Renderer& ren, int XOffset, int YOffset);
	void DrawFrontLayer(SDL_Renderer& ren, int XOffset, int YOffset);

	ObjectLayer* GetObjectLayer(string key);
	vector<SDL_Rect*> GetRects() { return this->rects; }
	vector<TileSet*> GetTileSets() { return this->tilesets; }
	SDL_Rect GetBounds() { return bounds; }

	std::vector<Node> GetNodes() 
	{
		vector<Node> returnNodes;
		for (Node* node : nodes)
		{
			returnNodes.push_back(*node);
		}
		return returnNodes; 
	};
private:
	void GenerateGraph();
	bool IntersectsWithCollisionLayer(SDL_Rect wp1, SDL_Rect wp2);
	std::vector<Node*> nodes;
	bool ExistsInMap(Node* n, SDL_Rect* rect);
};