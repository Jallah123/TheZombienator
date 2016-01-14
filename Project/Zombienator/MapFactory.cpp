#include "MapFactory.h"

void MapFactory::StoryMode() {

	EmptyQueue();

	mapQueue.push(new LandscapeMap());
	mapQueue.push(new SnowMap());
	mapQueue.push(new WunderlandMap());
}

void MapFactory::TutorialMode() {

	EmptyQueue();

	mapQueue.push(new TutorialMap());
}

Map * MapFactory::NextMap() {

	if(mapQueue.size() > 0){
		Map * nextMap = mapQueue.front();
		mapQueue.pop();

		return nextMap;
	}
	return nullptr;

}

bool MapFactory::IsQueueEmpty() {

	if (mapQueue.size() > 0) {
		return false;
	}

	return true;
}

void MapFactory::SetCustomQueue(vector<string> maps)
{
	EmptyQueue();
	for (string& s : maps)
	{
		mapQueue.push(new Map{ s });
	}
}

void MapFactory::EmptyQueue() {

	while (!mapQueue.empty()) { mapQueue.pop(); }
}

MapFactory::~MapFactory()
{
	this->EmptyQueue();
}