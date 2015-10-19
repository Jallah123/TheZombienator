#pragma once
#include <vector>
using namespace std;

class CollisionLayer
{
public:
	CollisionLayer();
	vector<vector<int>> getGIDs();
	void addGID(vector<int>);
	int getGID(int x, int y);
private:
	string name;
	vector<vector<int>> gIDs;

protected:

};