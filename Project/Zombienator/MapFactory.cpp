#include "MapFactory.h"

void MapFactory::StoryMode() {

	mapQueue.push(new LandscapeMap());
	mapQueue.push(new SnowMap());
	mapQueue.push(new WunderlandMap());

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

void MapFactory::EmptyQueue() {

	while (!mapQueue.empty()) { mapQueue.pop(); }
}

MapFactory::~MapFactory()
{
	this->EmptyQueue();
}