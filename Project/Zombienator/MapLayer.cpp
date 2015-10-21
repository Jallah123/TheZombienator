#include <iostream>
#include "MapLayer.h"
using namespace std;

MapLayer::MapLayer() {

}

MapLayer::MapLayer(string _name)
{
	name = _name;
}

string MapLayer::getName()
{
	return name;
}

vector<vector<int>> MapLayer::getGIDs()
{
	return gIDs;
}

int MapLayer::getGID(int x, int y) 
{
	if (gIDs.at(x).at(y) < 0) {
		return 0;
	}
	return gIDs.at(x).at(y);
}

void MapLayer::addGID(vector<int> gID)
{
	gIDs.push_back(gID);
}
