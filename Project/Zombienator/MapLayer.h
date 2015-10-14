#pragma once
#include <vector>
using namespace std;

class MapLayer
{
	public:
		MapLayer();
		MapLayer(char* _name);
		char* getName();
		vector<int> getGIDs();
		void setGID(int gID);

	private:
		char* name;
		vector<int> gIDs;

	protected:

};