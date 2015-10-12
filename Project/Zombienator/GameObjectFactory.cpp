#include "GameObjectFactory.h"



std::map<std::string, std::function<GameObject*(void)>> GameObjectFactory::registry;

GameObjectFactory::~GameObjectFactory()
{
}

void GameObjectFactory::Register(std::string name, std::function<GameObject*(void)> fn)
{
	GameObjectFactory::registry[name] = fn;
}

std::shared_ptr<GameObject> GameObjectFactory::Create(std::string name)
{
	GameObject* instance = nullptr;

	// find name in the registry and call factory method.
	/*auto it = GameObjectFactory::registry.find(name);
	if (it != GameObjectFactory::registry.end())
		instance = it->second();*/

	// wrap instance in a shared ptr and return
	if (instance != nullptr)
		return std::shared_ptr<GameObject>(instance);
		
	return nullptr;
}