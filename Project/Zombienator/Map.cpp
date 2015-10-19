#include "Map.h"
#include "MapLayer.h"
#include "CollisionLayer.h"
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

void Map::addCollisionLayer(CollisionLayer _collisionLayer)
{
	std::vector<CollisionLayer>::iterator it;

	it = collisionLayers.begin();
	collisionLayers.insert(it, _collisionLayer);

	cout << "CollisionLayer rendered" << endl;
}

Map::~Map() 
{
	
}