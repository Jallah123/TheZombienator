#pragma once
#include "Behaviour.h"
class Map;
class CharacterContainer;

class CollideBehaviour :
	public Behaviour
{
protected:
	CharacterContainer* characterContainer = nullptr;
	Map* map = nullptr;
	ObjectLayer* collisionLayer = nullptr;
public:
	CollideBehaviour();
	void SetCharacterContainer(CharacterContainer* c) { this->characterContainer = c; }
	void SetMap(Map* m);
	virtual ~CollideBehaviour();
	virtual bool Collide(float dt) = 0;
};

