

#include "BehaviourFactory.h"


//
// DO NOT FORGET TO INITIALIZE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
std::map<std::string, std::function<Behaviour*(void)>> BehaviourFactory::registry;

BehaviourFactory::~BehaviourFactory()
{
}

void BehaviourFactory::Register(std::string name, std::function<Behaviour*(void)> fn)
{
	BehaviourFactory::registry[name] = fn;
}

DrawBehaviour* BehaviourFactory::CreateDrawBehaviour(std::string name, GameObject* obj)
{
	Behaviour* instance = nullptr;

	// find name in the registry and call factory method.
	auto it = BehaviourFactory::registry.find(name);
	if (it != BehaviourFactory::registry.end())
		instance = it->second();

	// wrap instance in a shared ptr and return
	if (instance != nullptr) {
		instance->SetGameObject(obj);//link the behaviour to its gameObject
		return (DrawBehaviour*)instance;
	}

	return nullptr;
}

AnimateBehaviour* BehaviourFactory::CreateAnimateBehaviour(std::string name, GameObject * obj)
{
	Behaviour* instance = nullptr;

	// find name in the registry and call factory method.
	auto it = BehaviourFactory::registry.find(name);
	if (it != BehaviourFactory::registry.end())
		instance = it->second();

	// wrap instance in a shared ptr and return
	if (instance != nullptr) {
		instance->SetGameObject(obj);//link the behaviour to its gameObject
		return (AnimateBehaviour*)instance;
	}

	return nullptr;
}
