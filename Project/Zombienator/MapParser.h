#pragma once
#include "Map.h"
#include <SDL.h>
#include <memory>

class MapParser
{
public:
	MapParser();
	unique_ptr<Map> ParseJsonMap(string path);
	vector<SDL_Rect*> GenerateSprites(string path);
	~MapParser() {};
private:

};

