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
	GameObject* instance = Find("mike");
	if (instance != nullptr) {
		Mike* cInstance = dynamic_cast<Mike*>(instance);
		std::cout << "GameObjectFactory Character: " << cInstance << std::endl;
		return cInstance;
	}
	return nullptr;
}
Zombie* GameObjectFactory::CreateZombie(std::string name)
{
	GameObject* instance = Find(name);
	if (instance != nullptr) {
		Zombie* cInstance = dynamic_cast<Zombie*>(instance);
		std::cout << "GameObjectFactory Zombie: " << cInstance << std::endl;
		return cInstance;
	}
	return nullptr;
}
