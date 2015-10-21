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

bool Map::checkCollision(int _x, int _y, int _width, int _height) {
	
	SDL_Rect unitRectangle = { _x, _y, _width, _height };

	for (int j = collisionLayers.size() - 1; j >= 0; j--)
	{
		vector<CollisionObject> collisionObjects = collisionLayers[j].getCollisionObjects();

		for (int k = collisionObjects.size() - 1; k >= 0; k--)
		{

			SDL_Rect collisionRectangle = { 
				collisionObjects[k].getX(),
				collisionObjects[k].getY(),
				collisionObjects[k].getWidth(),
				collisionObjects[k].getHeight()
			};

			if (checkRectangleCollision(unitRectangle, collisionRectangle)) {
				return true;
			}
			

		}

	}

	return false;

}


bool Map::checkRectangleCollision(SDL_Rect unitRectangle, SDL_Rect collisionRectangle) {
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of unitRectangle
	leftA = unitRectangle.x;
	rightA = unitRectangle.x + unitRectangle.w;
	topA = unitRectangle.y;
	bottomA = unitRectangle.y + unitRectangle.h;

	//Calculate the sides of collisionRectangle
	leftB = collisionRectangle.x;
	rightB = collisionRectangle.x + collisionRectangle.w;
	topB = collisionRectangle.y;
	bottomB = collisionRectangle.y + collisionRectangle.h;

	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	return true;
}

Map::~Map() 
{
	
}