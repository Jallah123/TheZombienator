#pragma once
#include "Map.h"
#include <memory>
#include <json.h>

class MapParser
{
private:
	Map* map = nullptr;
	void ParseJson(char* path);
	
	Layer* ObjectType(Json::Value json);
	Layer* TileType(Json::Value json);

	void ParseTilesets(Json::Value json);
	void SetBaseValues(Json::Value json, Layer* l);
public:
	MapParser(Map* map);
	~MapParser();
	
};

