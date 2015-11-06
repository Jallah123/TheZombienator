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

	for (auto& lval : layers) {
		Layer* l = nullptr;
		string type = lval.get("type", "unknownType").asString();
		
		if (type == tileType)
			l = TileType(lval);

		if (type == objectType)
			l = ObjectType(lval);
				
		map->AddLayer(l);
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
		string img = t.get("image", "unkownImage").asString();
		int gid = t.get("firstgid", -1).asInt();
		int imgW = t.get("imagewidth", -1).asInt();
		int imgH = t.get("imageheight", -1).asInt();
		int tW = t.get("tilewidth", -1).asInt();
		int tH = t.get("tileheight", -1).asInt();
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
/*
unique_ptr<Map> MapParser::ParseJsonMap(string path)
{
	
	string  imageLocation = "assets/maps/" + root["tilesets"][0]["image"].asString();
	unique_ptr<Map> map(new Map(imageLocation));	
	
	for (int i = 0; i < layers.size(); i++) {
		
		Json::Value layer = layers[i];
		string name = layer.get("name", "noname").asString();
		if (name != "Collision") {
			int width = layer.get("width", 0).asInt();

			cout << name << endl;

			MapLayer ml{ name };
			vector<int> currentRow;

			int size = layer["data"].size();

			for (int x = 1; x <= size; x++) {
				int data = layer["data"][x - 1].asInt() - 1;
				currentRow.push_back(data);

				if (x % 40 == 0 && x != 0) {
					ml.addGID(currentRow);
					currentRow.clear();
				}
			}
			map.get()->addMapLayer(ml);
		}
		else { // Collision layer
			
			CollisionLayer cl;

			int size = layer["objects"].size();

			for (int x = 1; x <= size; x++) {
				int _id = layer["objects"][x - 1]["id"].asInt();
				int _x = layer["objects"][x - 1]["x"].asInt();
				int _y = layer["objects"][x - 1]["y"].asInt();
				int _width = layer["objects"][x - 1]["width"].asInt();
				int _height = layer["objects"][x - 1]["height"].asInt();

				CollisionObject collisionObject = CollisionObject(_id, _x, _y, _width, _height);
				cl.addCollisionObject(collisionObject);

			}

			map.get()->addCollisionLayer(cl);
		}
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
}*/