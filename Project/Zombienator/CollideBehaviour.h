#pragma once
#include "Behaviour.h"
#include <vector>

using std::vector;
class Map;
class GameObjectContainer;

class CollideBehaviour :
	public Behaviour
{
protected:
	GameObjectContainer* gameObjectContainer = nullptr;
	Map* map = nullptr;
public:
	CollideBehaviour();
	void SetGameObjectContainer(GameObjectContainer* c) { this->gameObjectContainer = c; }
	void SetMap(Map* m);
	virtual ~CollideBehaviour();
	virtual void Collide(float dt) = 0;

	SDL_Rect* Closest(vector<SDL_Rect> rects);
};

