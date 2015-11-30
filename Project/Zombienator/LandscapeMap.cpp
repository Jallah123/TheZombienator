#pragma once
#include "LandscapeMap.h"

LandscapeMap::LandscapeMap(SDL_Renderer& ren) : Map("assets/maps/landscape-1280x640.json", ren)
{
}


LandscapeMap::~LandscapeMap()
{
}