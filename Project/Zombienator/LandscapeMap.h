#pragma once
#include "Map.h"

class LandscapeMap : public Map
{
public:
	LandscapeMap(SDL_Renderer& ren);
	~LandscapeMap();
};