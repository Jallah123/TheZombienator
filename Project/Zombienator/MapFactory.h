#pragma once
#include "AbstractScreen.h"
#include "Map.h"

class MapFactory
{
public:
	static Map * MapFactory::NextMap(SDL_Renderer* ren);
private:
	
};

