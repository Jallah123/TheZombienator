#pragma once
#include <string>
#include <map>
#include <vector>
#include <SDL_rect.h>
#include <SDL_render.h>

#include "Layer.h"
#include "TileSet.h"
#include "ObjectLayer.h"

using std::string;
using std::vector;

class MapParser;
class CollisionLayer;

class Map
{
private:
	std::string path;
	
	int width = 0;
	int height = 0;
	int tileWidth = 0;
	int tileHeight = 0;
	MapParser* parser = nullptr;

	std::map<string, Layer*> layers{};
	vector<TileSet*> tilesets{};
	vector<SDL_Rect*> rects{};
	SDL_Renderer* renderer;
public:
	Map(std::string path, SDL_Renderer& ren);
	~Map();

	std::string GetPath() const { return this->path; }
	void TileSize(int w, int h) { tileWidth = w; tileHeight = h; }
	void Size(int w, int h);

	int Width() { return width; }
	int Height() { return height; }

	int TileWidth() { return tileWidth; }
	int TileHeight() { return tileHeight; }

	void AddLayer(Layer* l) { layers.insert({ l->Name(), l }); }
	void AddTileset(TileSet* ts);

	void Draw(SDL_Renderer& ren, int XOffset, int YOffset);

	ObjectLayer* GetObjectLayer(string key);
	vector<SDL_Rect*> GetRects() { return this->rects; }
	vector<TileSet*> GetTileSets() { return this->tilesets; }
};