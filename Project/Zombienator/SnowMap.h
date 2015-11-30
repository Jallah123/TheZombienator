#pragma once
#include "Map.h"

class SnowMap : public Map
{
public:
	SnowMap(SDL_Renderer& ren);
	~SnowMap();
};