#pragma once
#include "SnowMap.h"

SnowMap::SnowMap(SDL_Renderer& ren) : Map("assets/maps/snow-1280x640.json", ren)
{
}


SnowMap::~SnowMap()
{
}