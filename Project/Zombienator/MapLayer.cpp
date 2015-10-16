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
	return gIDs.at(x).at(y);
}

void MapLayer::addGID(vector<int> gID)
{
	gIDs.push_back(gID);

	/*
	for (int i = 0; i < gID.size(); i++)
		cout << gID[i] << ", ";
	 cout << endl;
	 */
}
