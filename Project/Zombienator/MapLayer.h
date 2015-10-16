#pragma once
#include <vector>
using namespace std;

class MapLayer
{
	public:
		MapLayer();
		MapLayer(string _name);
		string getName();
		vector<vector<int>> getGIDs();
		void addGID(vector<int>);
		int getGID(int x, int y);
	private:
		string name;
		vector<vector<int>> gIDs;

	protected:

};