#include "Map.h"
#include "MapLayer.h"
#include <iostream>
using namespace std;

Map::Map(string _img_path)
{
	img_path = _img_path;
}

void Map::setTexture(SDL_Texture* text)
{
	texture = text;
}

string Map::getImagePath() {
	return img_path;
}

void Map::addMapLayer(MapLayer _mapLayer)
{
	std::vector<MapLayer>::iterator it;

	it = mapLayers.begin();
	mapLayers.insert(it, _mapLayer);

	cout << "MapLayer rendered - " << _mapLayer.getName().c_str() << endl;
}

Map::~Map() 
{
	
}