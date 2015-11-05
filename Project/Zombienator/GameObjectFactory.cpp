#include "GameObjectFactory.h"
#include "GameObject.h"
#include "Character.h"
#include "Mike.h"
#include "Zombie.h"
#include "Map.h"
#include "NormalBullet.h"

//
// DO NOT FORGET TO INITIALIZE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
std::map<std::string, std::function<GameObject*(void)>> GameObjectFactory::registry;
Map* GameObjectFactory::mapLevel = nullptr;
DrawContainer*		GameObjectFactory::drawContainer = nullptr;
AnimateContainer*	GameObjectFactory::animateContainer = nullptr;
ActionContainer*	GameObjectFactory::actionContainer = nullptr;
MoveContainer*		GameObjectFactory::moveContainer = nullptr;
CollideContainer*	GameObjectFactory::collideContainer = nullptr;
CharacterContainer* GameObjectFactory::characterContainer = nullptr;
SDL_Renderer*		GameObjectFactory::renderer = nullptr;


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

void GameObjectFactory::SetContainers(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, ActionContainer* actionC, CollideContainer* collideC, CharacterContainer* characterC, SDL_Renderer* ren)
{
	drawContainer = drawC;
	animateContainer = animC;
	moveContainer = moveC;
	actionContainer = actionC;
	collideContainer = collideC;
	characterContainer = characterC;
	renderer = ren;
}

void GameObjectFactory::Register(std::string name, std::function<GameObject*(void)> fn)
{
	//we need to register an instance that already has all of the containers.
	GameObjectFactory::registry[name] = fn;
}

void GameObjectFactory::SetLevel(Map * l)
{
	mapLevel = l;
}

Map * GameObjectFactory::GetLevel()
{
	return mapLevel;
}

Mike* GameObjectFactory::CreateMike()
{
	GameObject* instance = GameObjectFactory::Find("mike");
	if (instance != nullptr) {
		Mike* cInstance = dynamic_cast<Mike*>(instance);
		cInstance->setMap(mapLevel);
		cInstance->Init(drawContainer, animateContainer, moveContainer, actionContainer, collideContainer, characterContainer, renderer);
		return cInstance;
	}
	return nullptr;
}
Zombie* GameObjectFactory::CreateZombie()
{
	GameObject* instance = GameObjectFactory::Find("zombie");
	if (instance != nullptr) {
		Zombie* cInstance = dynamic_cast<Zombie*>(instance);
		cInstance->setMap(mapLevel);
		cInstance->Init(drawContainer, animateContainer, moveContainer, actionContainer, collideContainer, characterContainer, renderer);
		return cInstance;
	}
	return nullptr;
}

NormalBullet * GameObjectFactory::CreateNormalBullet(PlayableCharacter * obj)
{
	GameObject* instance = GameObjectFactory::Find("bullet");

	if (instance != nullptr) {
		NormalBullet* cInstance = dynamic_cast<NormalBullet*>(instance);
		cInstance->Init(drawContainer, moveContainer, collideContainer);
		cInstance->SetOrigin(obj);//link the behaviour to its gameObject
		return cInstance;
	}

	return nullptr;
}
