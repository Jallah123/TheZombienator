#include "Map.h"
#include "MapLayer.h"
#include <iostream>
using namespace std;

Map::Map(char * _img_path)
{
	img_path = _img_path;
}

char * Map::getImage() {
	return img_path;
}

void Map::setMapLayer(MapLayer _mapLayer)
{
	std::vector<MapLayer>::iterator it;

	it = mapLayers.begin();
	mapLayers.insert(it, _mapLayer);

	cout << "MapLayer rendered - " << _mapLayer.getName() << endl;
}
