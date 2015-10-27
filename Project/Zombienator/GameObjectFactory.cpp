#include "GameObjectFactory.h"
#include "GameObject.h"
#include "Character.h"
#include "Mike.h"
#include "Zombie.h"

//
// DO NOT FORGET TO INITIALIZE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
std::map<std::string, std::function<GameObject*(void)>> GameObjectFactory::registry;

GameObject * GameObjectFactory::Find(std::string name)
{
	GameObject* instance = nullptr;
	auto it = GameObjectFactory::registry.find(name);
	if (it != GameObjectFactory::registry.end())
		instance = it->second();

	if (instance != nullptr) return instance;
	return nullptr;
}

GameObjectFactory::~GameObjectFactory()
{
}

void GameObjectFactory::Register(std::string name, std::function<GameObject*(void)> fn)
{
	//we need to register an instance that already has all of the containers.
		GameObjectFactory::registry[name] = fn;
}

Mike* GameObjectFactory::CreateMike()
{
	GameObject* instance = GameObjectFactory::Find("mike");
	if (instance != nullptr) {
		Mike* cInstance = dynamic_cast<Mike*>(instance);
		return cInstance;
	}
	return nullptr;
}
Zombie* GameObjectFactory::CreateZombie()
{
	GameObject* instance = GameObjectFactory::Find("zombie");
	if (instance != nullptr) {
		Zombie* cInstance = dynamic_cast<Zombie*>(instance);
		return cInstance;
	}
	return nullptr;
}
