#include <iostream>
#include "MapLayer.h"
using namespace std;

MapLayer::MapLayer() {

}

MapLayer::MapLayer(char * _name)
{
	name = _name;
}

char * MapLayer::getName()
{
	return name;
}

vector<int> MapLayer::getGIDs()
{
	return gIDs;
}

void MapLayer::setGID(int gID)
{
	std::vector<int>::iterator it;

	it = gIDs.begin();
	gIDs.insert(it, gID);

	//cout << gID << endl;


}
