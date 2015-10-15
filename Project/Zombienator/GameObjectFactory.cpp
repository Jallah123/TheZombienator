#include "GameObjectFactory.h"


//
// DO NOT FORGET TO INITIALIZE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
std::map<std::string, std::function<GameObject*(void)>> GameObjectFactory::registry;

GameObjectFactory::~GameObjectFactory()
{
}

void GameObjectFactory::Register(std::string name, std::function<GameObject*(void)> fn)
{
	//we need to register an instance that already has all of the containers.
	GameObjectFactory::registry[name] = fn;
}

Character* GameObjectFactory::CreateCharacter(std::string name)
{
	GameObject* instance = nullptr;

	// find name in the registry and call factory method.
	auto it = GameObjectFactory::registry.find(name);
	if (it != GameObjectFactory::registry.end())
		instance = it->second();

	if (instance != nullptr) {
		Character* cInstance = (Character*)&instance;
		std::cout << "GameObjectFactory Character: " << &cInstance << std::endl;
		return cInstance;
	}
	return nullptr;
}
/*
std::shared_ptr<GameObject> GameObjectFactory::Create(std::string name)
{
	GameObject* instance = nullptr;

	// find name in the registry and call factory method.
	auto it = GameObjectFactory::registry.find(name);
	if (it != GameObjectFactory::registry.end())
		instance = it->second();

	// wrap instance in a shared ptr and return
	if (instance != nullptr) {
		return std::shared_ptr<GameObject>(instance);
	}
		
	return nullptr;
}*/