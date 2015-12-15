#pragma once
#include "AbstractScreen.h"
#include "LandscapeMap.h"
#include "WunderlandMap.h"
#include "SnowMap.h"
#include "TutorialMap.h"
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
	void MapFactory::TutorialMode();
	void MapFactory::EmptyQueue();
	bool MapFactory::IsQueueEmpty();

	static MapFactory* GetInstance() {
		static MapFactory f;
		return &f;
	}
};

