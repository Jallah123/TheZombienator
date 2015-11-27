#include "GameObjectContainer.h"
#include "GameObjectFactory.h"
#include "Mike.h"
#include "Zombie.h"
#include "Map.h"
#include "Quadtree.h"


GameObjectContainer::GameObjectContainer()
{
	GameObjectFactory::Instance()->Register("mike", [](void) -> GameObject* {return new Mike(); });
	GameObjectFactory::Instance()->Register("zombie", [](void) -> GameObject* {return new Zombie(); });
}

GameObjectContainer::GameObjectContainer(Map * m, Quadtree * t): map(m), tree(t)
{
	ObjectLayer* col = map->GetObjectLayer("Collision");
	for (auto& r : col->GetRects()) {
		GameObject* go = new GameObject();
		go->SetSize(r->w, r->h);
		go->SetPosition(r->x, r->y);
		AddGameObject(go);
	}
}


GameObjectContainer::~GameObjectContainer()
{
	std::vector<GameObject*>::reverse_iterator it;
	for (it = objects.rbegin(); it != objects.rend(); ++it)
		delete *it;

	objects.clear();

	for (it = arrRemove.rbegin(); it != arrRemove.rend(); ++it)
		delete *it;

	arrRemove.clear();
}

vector<GameObject*> GameObjectContainer::GetGameObjects(float x, float y)
{
	return tree->GetObjectsAt(x, y);
}

void GameObjectContainer::AddGameObject(GameObject * c)
{
	objects.push_back(c);
}

void GameObjectContainer::Remove(GameObject * c)
{
	if (dynamic_cast<Zombie*>(c)) StatsController::Instance()->AddKill();
	objects.erase(std::remove(objects.begin(), objects.end(), c), objects.end());
}

void GameObjectContainer::RemoveAll()
{
	if (arrRemove.size() == 0) return;
	for (const auto& c : arrRemove)
	{
		Remove(c);
	}
	arrRemove.clear();
}

void GameObjectContainer::SetMap(Map * m)
{
	map = m;
	ObjectLayer* col = map->GetObjectLayer("Collision");
	for (auto& r : col->GetRects()) {
		GameObject* go = new GameObject();
		go->SetSize(r->w, r->h);
		go->SetPosition(r->x, r->y);
		AddGameObject(go);
	}
}

SDL_Rect GameObjectContainer::GetBounds()
{
	return map->GetBounds();
}