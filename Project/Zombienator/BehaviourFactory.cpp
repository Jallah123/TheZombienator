#pragma once
#include <SDL_render.h>
#include "Behaviour.h"
#include "DrawBehaviour.h"
#include "AnimateBehaviour.h"
#include "MoveBehaviour.h"
#include "ActionBehaviour.h"
#include "BehaviourFactory.h"
#include "CollideBehaviour.h"

//
// DO NOT FORGET TO INITIALIZE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
std::map<std::string, std::function<Behaviour*(void)>> BehaviourFactory::registry;
DrawContainer*		BehaviourFactory::drawContainer = nullptr;
AnimateContainer*	BehaviourFactory::animateContainer = nullptr;
ActionContainer*	BehaviourFactory::actionContainer = nullptr;
MoveContainer*		BehaviourFactory::moveContainer = nullptr;
CollideContainer*	BehaviourFactory::collideContainer = nullptr;
CharacterContainer* BehaviourFactory::characterContainer = nullptr;
SDL_Renderer*		BehaviourFactory::renderer = nullptr;

BehaviourFactory::~BehaviourFactory()
{
}

void BehaviourFactory::SetContainers(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, ActionContainer* actionC, CollideContainer* collideC, CharacterContainer* characterC, SDL_Renderer* ren)
{
	drawContainer = drawC;
	animateContainer = animC;
	moveContainer = moveC;
	actionContainer = actionC;
	collideContainer = collideC;
	characterContainer = characterC;
	renderer = ren;
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

CollideBehaviour * BehaviourFactory::CreateCollideBehaviour(std::string name, GameObject * obj)
{
	Behaviour* instance = BehaviourFactory::Find(name);

	if (instance != nullptr) {
		CollideBehaviour* cInstance = dynamic_cast<CollideBehaviour*>(instance);
		cInstance->SetGameObject(obj);//link the behaviour to its gameObject
		cInstance->SetCharacterContainer(characterContainer);
		return cInstance;
	}

	return nullptr;
}
