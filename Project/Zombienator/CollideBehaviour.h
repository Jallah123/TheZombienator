#pragma once
#include "Behaviour.h"
#include <vector>

using std::vector;
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
	virtual void Collide(float dt) = 0;

	SDL_Rect* Closest(vector<SDL_Rect> rects);
};

