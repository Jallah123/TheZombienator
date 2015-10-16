#include "MapParser.h"
#include "MapRender.h"
#include "MapLayer.h"
#include "Map.h"
#include <fstream>
#include <json.h>

MapParser::MapParser()
{
}

unique_ptr<Map> MapParser::ParseJsonMap(string path)
{
	Json::Value root;
	std::ifstream config_doc(path, std::ifstream::binary);
	config_doc >> root;

	Json::Value layers = root["layers"];
	unique_ptr<Map> map(new Map("assets/maps/TestMap/mountain_landescape_23.png"));	

	for (int i = 0; i < layers.size(); i++) {
		Json::Value layer = layers[i];
		string name = layer.get("name", "noname").asString();
		int width = layer.get("width", 0).asInt();

		cout << name << endl;

		MapLayer ml{ name };
		vector<int> currentRow;

		int size = layer["data"].size();

		for (int x = 1; x <= size; x++) {
			int data = layer["data"][x - 1].asInt() - 1;
			currentRow.push_back(data);
			if (x % 32 == 0 && x != 0) {
				ml.addGID(currentRow);
				currentRow.clear();
			}
		}
		map.get()->addMapLayer(ml);
	}
	config_doc.close();
	return map;
}

vector<SDL_Rect*> MapParser::GenerateSprites(string path)
{
	vector<SDL_Rect*> sprites;
	Json::Value root;
	std::ifstream config_doc(path, std::ifstream::binary);
	config_doc >> root;

	int spritesWidth = root["tilesets"][0]["tileheight"].asInt();
	int spriteHeight = root["tilesets"][0]["tilewidth"].asInt();
	int imageHeight = root["tilesets"][0]["imageheight"].asInt();
	int imageWidth = root["tilesets"][0]["imagewidth"].asInt();

	for (int y = 0; y < imageWidth; y += spritesWidth)
	{
		for (int x = 0; x < imageHeight; x += spriteHeight)
		{
			SDL_Rect* rect = new SDL_Rect();
			rect->h = spriteHeight;
			rect->w = spritesWidth;
			rect->x = x;
			rect->y = y;
			sprites.push_back(rect);
		}
	}
	return sprites;
}