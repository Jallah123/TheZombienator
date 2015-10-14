#pragma once
#include "MapLayer.h"
using namespace std;

class Map
{
public:
	Map(char* _img_path);
	char* getImage();
	void setMapLayer(MapLayer _mapLayer);
private:
	char* img_path;
	vector<MapLayer> mapLayers;
protected:

};