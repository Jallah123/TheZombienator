#pragma once
#include <vector>
#include "Layer.h"

using std::vector;
class TileSet;
class Map;

class TileLayer :
	public Layer
{
private:
	vector<size_t> tilesIDs{};
	TileSet* tileSet = nullptr;
public:
	TileLayer();
	TileLayer(Map* map);
	~TileLayer();

	TileSet* getTileSet() { return tileSet; };
	virtual void Draw(SDL_Renderer& ren, int XOffset, int YOffset) override;
	vector<size_t> TilesIDs() { return this->tilesIDs; }
	void AddTileID(size_t id);
	size_t GetTileID(size_t index) { return tilesIDs.at(index); }
};

