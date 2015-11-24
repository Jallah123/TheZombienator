#pragma once
#include "Behaviour.h"
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
};

