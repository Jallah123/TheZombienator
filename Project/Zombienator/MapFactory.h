#pragma once
#include "AbstractScreen.h"
#include "LandscapeMap.h"
#include "SnowMap.h"
#include <iostream>
#include <queue>

using namespace std;

class MapFactory
{
private:
	queue <Map*> mapQueue;

public:
	~MapFactory();

	Map * MapFactory::NextMap(SDL_Renderer* ren);
	void MapFactory::StoryMode(SDL_Renderer* ren);
	void MapFactory::EmptyQueue();

	static MapFactory* Instance() {
		static MapFactory f;
		return &f;
	}
};

