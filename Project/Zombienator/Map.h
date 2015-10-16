#pragma once
#include "MapLayer.h"
#include "SDL_image.h"
#include <memory>

using namespace std;

class Map
{
public:
	Map(string _img_path);
	string getImagePath();
	void addMapLayer(MapLayer _mapLayer);
	void setSprites(vector<SDL_Rect*> _sprites) { sprites = _sprites; };
	vector<SDL_Rect*> getSprites() { return sprites; };
	void setTexture(SDL_Texture* texture);
	SDL_Texture* getTexture() { return texture; };
	MapLayer getLayer() { return mapLayers[1]; };
	~Map();
private:
	SDL_Texture* texture;
	vector<SDL_Rect*> sprites;
	string img_path;
	vector<MapLayer> mapLayers;
protected:

};