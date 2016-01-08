#pragma once
#include <string>
#include <map>
#include <vector>
#include <SDL_rect.h>
#include <SDL_render.h>
#include "Layer.h"
#include "TileSet.h"
#include "MapParser.h"
#include "TileLayer.h"
#include "ObjectLayer.h"
#include "Node.h"
#include "Graph.h"
#include "SoundController.h"

using std::string;
using std::vector;

class MapParser;
class CollisionLayer;

class Map
{
private:
	string mapPath = "";
	string soundPath = "bgSound1.wav"; // Default music

	int width = 0;
	int height = 0;
	int tileWidth = 0;
	int tileHeight = 0;

	MapParser* parser = nullptr;
	SDL_Rect bounds = { 0,0,0,0 };

	map<string, Layer*> backLayers{};
	map<string, Layer*> frontLayers{};
	vector<TileSet*> tilesets{};
	vector<SDL_Rect*> rects{};
	SDL_Renderer* renderer;
	SoundController* SoundController = &SoundController::GetInstance();
public:
	Map(string mapPath);
	virtual ~Map();

	string GetMapPath() const { return this->mapPath; }
	string GetSoundPath() const { return this->mapPath; }
	void SetSoundPath(string soundPath) { this->soundPath = soundPath; }

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
	void Draw(SDL_Renderer& ren, int x, int y, int size);
	void DrawFrontLayer(SDL_Renderer& ren, int XOffset, int YOffset);

	void PlaySounds();

	ObjectLayer* GetObjectLayer(string key);
	vector<SDL_Rect*> GetRects() { return this->rects; }
	vector<TileSet*> GetTileSets() { return this->tilesets; }
	SDL_Rect GetBounds() { return bounds; }

	Graph* GetGraph() { return &graph; };

	bool IntersectsWithCollisionLayer(SDL_Rect wp1, SDL_Rect wp2);
	bool ExistsInMap(Node* n1, Node* n2);
private:
	Graph graph;
	void GenerateGraph();
};