#pragma once
#include "MapParser.h"
#include "Map.h"
#include "Layer.h"
#include "ObjectLayer.h"
#include "TileLayer.h"
#include <fstream>
#include <iostream>



MapParser::MapParser(Map* map) :map(map)
{
	ParseJson(map->GetPath());
	std::cout << "finished Parsing" << std::endl;
}

MapParser::~MapParser()
{
}

void MapParser::ParseJson(char * path)
{
	string tileType = "tilelayer";
	string objectType = "objectgroup";

	Json::Value root;
	std::ifstream config_doc(path, std::ifstream::binary);
	config_doc >> root;

	ParseTilesets(root);

	size_t tw = root.get("tilewidth", 0).asInt();
	size_t th = root.get("tileheight", 0).asInt();
	map->TileSize(tw, th);

	size_t width = root.get("width", 0).asInt();
	size_t height = root.get("height", 0).asInt();
	map->Size(width, height);

	Json::Value layers = root["layers"];

	std::string prefix = "Min";

	for (auto& lval : layers) {
		Layer* l = nullptr;
		string type = lval.get("type", "unknownType").asString();
		
		if (type == tileType)
			l = TileType(lval);

		if (type == objectType)
			l = ObjectType(lval);
				

		string name = lval.get("name", "unknownType").asString();

		if (name.rfind(prefix, 0) == 0)
			map->AddFrontLayer(l);
		else
			map->AddBackLayer(l);
	}
	
	config_doc.close();
}

Layer* MapParser::ObjectType(Json::Value json)
{
	ObjectLayer* ol = new ObjectLayer();
	SetBaseValues(json, ol);

	for (auto& i : json["objects"]) {
		int id = i.get("id", -1).asInt();
		int x = i.get("x", -1).asInt();
		int y = i.get("y", -1).asInt();
		int w = i.get("width", -1).asInt();
		int h = i.get("height", -1).asInt();

		ol->AddRect(new SDL_Rect{ x,y,w,h });
	}

	return ol;
}

Layer* MapParser::TileType(Json::Value json)
{
	TileLayer* tl = new TileLayer(map);
	SetBaseValues(json, tl);

	for (const auto& i : json["data"]) {
		tl->AddTileID(i.asInt()-1);
	}
	return tl;
}

void MapParser::ParseTilesets(Json::Value json)
{
	size_t tileWidth = json.get("tilewidth", 0).asInt();
	size_t tileHeight = json.get("tileheight", 0).asInt();
	
	
	for (auto& t : json["tilesets"]) {
		string img	= t.get("image", "unkownImage").asString();
		int gid		= t.get("firstgid", -1).asInt();
		int imgW	= t.get("imagewidth", -1).asInt();
		int imgH	= t.get("imageheight", -1).asInt();
		int tW		= t.get("tilewidth", -1).asInt();
		int tH		= t.get("tileheight", -1).asInt();
		map->AddTileset(new TileSet{ img,gid,imgW,imgH,tW,tH });
	}	
}

void MapParser::SetBaseValues(Json::Value json, Layer * l)
{
	string type = json.get("type", "unknownType").asString();
	string name = json.get("name", "unknownName").asString();
	
	int width = json.get("width", 0).asInt();
	int height = json.get("height", 0).asInt();

	l->Type(type);
	l->Name(name);
	l->Width(width);
	l->Height(height);
}