#pragma once
#include <vector>
#include <algorithm>
#include "StatsController.h"
#include <SDL_rect.h>
class GameObject;
class Map;
using std::vector;

class GameObjectContainer
{
public:
	GameObjectContainer();
	~GameObjectContainer();
	void Init();
	vector<GameObject*> GetGameObjects() { return objects; };
	void AddGameObject(GameObject* c);
	void Remove(GameObject* c);
	void RemoveAll();
	void SetMap(Map* m);
	SDL_Rect GetBounds();
private:
	Map* map = nullptr;
	vector<GameObject*> objects = {};
	vector<GameObject*> arrRemove = {};

};

