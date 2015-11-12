#pragma once
#include "Behaviour.h"
class Map;
class CharacterContainer;

class MoveBehaviour 
	: public Behaviour 
{
protected:
	Map* map = nullptr;
	ObjectLayer* collisionLayer = nullptr;
public:
	MoveBehaviour();
	virtual ~MoveBehaviour();

	void SetMap(Map* m);

	virtual void Move(float dt) = 0;
};