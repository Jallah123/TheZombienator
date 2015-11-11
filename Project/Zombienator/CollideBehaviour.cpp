#include "CollideBehaviour.h"
#include "Map.h"


CollideBehaviour::CollideBehaviour()
{
}


void CollideBehaviour::SetMap(Map * m)
{
	this->map = m;
	this->collisionLayer = map->GetObjectLayer("Collision");
}

CollideBehaviour::~CollideBehaviour()
{
}

SDL_Rect * CollideBehaviour::Closest(vector<SDL_Rect> rects)
{
	return nullptr;
}
