#include "MapFactory.h"

void MapFactory::StoryMode(SDL_Renderer* ren) {

	mapQueue.push(new LandscapeMap(*ren));
	mapQueue.push(new SnowMap(*ren));

}

Map * MapFactory::NextMap(SDL_Renderer* ren) {

	if(mapQueue.size() > 0){
		Map * nextMap = mapQueue.front();
		mapQueue.pop();

		return nextMap;
	}
	return nullptr;

}

void MapFactory::EmptyQueue() {

	while (!mapQueue.empty()) { mapQueue.pop(); }
}

MapFactory::~MapFactory()
{
	this->EmptyQueue();
}