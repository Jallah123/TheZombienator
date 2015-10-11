#include "GameObjectFactory.h"




GameObjectFactory::~GameObjectFactory()
{
}

std::shared_ptr<GameObject> GameObjectFactory::Create(std::string name)
{
	GameObject* instance = nullptr;

	// find name in the registry and call factory method.
	auto it = registry.find(name);
	if (it != registry.end())
		instance = it->second();

	// wrap instance in a shared ptr and return
	if (instance != nullptr)
		return std::shared_ptr<GameObject>(instance);
	
	return nullptr;
}
