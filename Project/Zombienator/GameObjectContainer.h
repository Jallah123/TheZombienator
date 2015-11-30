#pragma once
#include <vector>
#include <algorithm>
#include "StatsController.h"
#include <SDL_rect.h>
class GameObject;
class Map;
class Quadtree;
using std::vector;

class GameObjectContainer
{
public:
	GameObjectContainer();
	GameObjectContainer(Map* m, Quadtree* t);
	~GameObjectContainer();
	vector<GameObject*> GetGameObjects() { return objects; };
	vector<GameObject*> GetGameObjects(float x, float y);
	void AddGameObject(GameObject* c);
	void Remove(GameObject* c);
	void RemoveAll();
	void SetMap(Map* m);
	SDL_Rect GetBounds();
private:
	Map* map = nullptr;
	Quadtree* tree = nullptr;
	vector<GameObject*> objects = {};
	vector<GameObject*> arrRemove = {};
	
};

