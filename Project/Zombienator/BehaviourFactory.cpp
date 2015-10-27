
#include "Behaviour.h"
#include "DrawBehaviour.h"
#include "AnimateBehaviour.h"
#include "MoveBehaviour.h"
#include "ActionBehaviour.h"
#include "BehaviourFactory.h"


//
// DO NOT FORGET TO INITIALIZE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
std::map<std::string, std::function<Behaviour*(void)>> BehaviourFactory::registry;

BehaviourFactory::~BehaviourFactory()
{
}

Behaviour * BehaviourFactory::Find(std::string name)
{
	Behaviour* instance = nullptr;
	auto it = BehaviourFactory::registry.find(name);
	if (it != BehaviourFactory::registry.end())
		instance = it->second();
	if (instance != nullptr) return instance;
	return nullptr;
}

void BehaviourFactory::Register(std::string name, std::function<Behaviour*(void)> fn)
{
	BehaviourFactory::registry[name] = fn;
}

DrawBehaviour* BehaviourFactory::CreateDrawBehaviour(std::string name, GameObject* obj)
{
	Behaviour* instance = BehaviourFactory::Find(name);
	
	if (instance != nullptr) {
		DrawBehaviour* cInstance = dynamic_cast<DrawBehaviour*>(instance);
		cInstance->SetGameObject(obj);//link the behaviour to its gameObject
		return cInstance;
	}

	return nullptr;
}

AnimateBehaviour* BehaviourFactory::CreateAnimateBehaviour(std::string name, GameObject * obj)
{
	Behaviour* instance = BehaviourFactory::Find(name);
	
	if (instance != nullptr) {
		AnimateBehaviour* cInstance = dynamic_cast<AnimateBehaviour*>(instance);
		cInstance->SetGameObject(obj);//link the behaviour to its gameObject
		return cInstance;
	}

	return nullptr;
}

MoveBehaviour* BehaviourFactory::CreateMoveBehaviour(std::string name, GameObject * obj)
{
	Behaviour* instance = BehaviourFactory::Find(name);

	if (instance != nullptr) {
		MoveBehaviour* cInstance = dynamic_cast<MoveBehaviour*>(instance);
		cInstance->SetGameObject(obj);//link the behaviour to its gameObject
		return cInstance;
	}

	return nullptr;
}

ActionBehaviour * BehaviourFactory::CreateActionBehaviour(std::string name, GameObject * obj)
{
	Behaviour* instance = BehaviourFactory::Find(name);

	if (instance != nullptr) {
		ActionBehaviour* cInstance = dynamic_cast<ActionBehaviour*>(instance);
		cInstance->SetGameObject(obj);//link the behaviour to its gameObject
		return cInstance;
	}

	return nullptr;
}
