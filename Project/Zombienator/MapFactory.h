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

	Map * MapFactory::NextMap();
	void MapFactory::StoryMode();
	void MapFactory::EmptyQueue();
	bool MapFactory::IsQueueEmpty();

	static MapFactory* Instance() {
		static MapFactory f;
		return &f;
	}
};

