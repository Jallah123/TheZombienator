#include "MapRender.h"
#include "MapLayer.h"
#include "Map.h"
#include <fstream>
#include <json.h>


MapRender::MapRender(char* xml_url)
{
	Json::Value root;
	std::ifstream config_doc("C:\\Users\\Tojba\\Documents\\TheZombienator\\Project\\Zombienator\\assets\\maps\\map-1280x640.json", std::ifstream::binary);
	config_doc >> root;

	string s = root.get("height", "1").asString();
	Json::Value layers = root["layers"];
	Map map{ "assets/maps/sprites-landscape.png" };

	for (int i = 0; i < layers.size(); i++) {
		Json::Value layer = layers[i];
		string name = layer.get("name", "noname").asString();
		int width = layer.get("width", 0).asInt();

		cout << name << endl;

		MapLayer ml{name};
		vector<int> currentRow;

		int size = layer["data"].size();

		for (int x = 1; x <= size; x++) {
			currentRow.push_back(layer["data"][x-1].asInt());
			if (x % width == 0 && x != 0) {
				ml.addGID(currentRow);
				currentRow.clear();
			}
		}
		map.addMapLayer(ml);
	}
}

void MapRender::renderLayer(pugi::xml_node layer, MapLayer ml) {



}