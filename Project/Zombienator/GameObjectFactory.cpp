#include <SDL_render.h>
#include "GameObjectFactory.h"
#include "GameObject.h"
#include "Character.h"
#include "Mike.h"
#include "Zombie.h"
#include "Map.h"
#include "NormalBullet.h"
#include "MachineGunBullet.h"
#include "Medkit.h"
#include "AmmoBox.h"

#include "DrawContainer.h"
#include "AnimateContainer.h"
#include "ActionContainer.h"
#include "MoveContainer.h"
#include "CollideContainer.h"
#include "GameObjectContainer.h"
#include "NumberUtility.h"
//
// DO NOT FORGET TO INITIALIZE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
std::map<std::string, std::function<GameObject*(void)>> GameObjectFactory::registry{};
DrawContainer*		GameObjectFactory::drawContainer = nullptr;
AnimateContainer*	GameObjectFactory::animateContainer = nullptr;
ActionContainer*	GameObjectFactory::actionContainer = nullptr;
MoveContainer*		GameObjectFactory::moveContainer = nullptr;
CollideContainer*	GameObjectFactory::collideContainer = nullptr;
GameObjectContainer* GameObjectFactory::gameObjectContainer = nullptr;
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

void GameObjectFactory::SetContainers(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, ActionContainer* actionC, CollideContainer* collideC, GameObjectContainer* gameObjectC, SDL_Renderer* ren)
{
	drawContainer = drawC;
	animateContainer = animC;
	moveContainer = moveC;
	actionContainer = actionC;
	collideContainer = collideC;
	gameObjectContainer = gameObjectC;
	renderer = ren;
	GameObjectFactory::Instance()->Register("mike", [&](void) -> GameObject* {
		return new Mike(drawContainer, animateContainer, moveContainer, collideContainer, actionContainer, gameObjectContainer); });
	GameObjectFactory::Instance()->Register("zombie", [&](void) -> GameObject* {
		return new Zombie(drawContainer, animateContainer, moveContainer, collideContainer, actionContainer, gameObjectContainer); });
	GameObjectFactory::Instance()->Register("Medkit", [&](void) -> GameObject* {
		return new Medkit(drawContainer, animateContainer, moveContainer, collideContainer, actionContainer, gameObjectContainer); });
	GameObjectFactory::Instance()->Register("AmmoBox", [&](void) -> GameObject* {
		return new AmmoBox(drawContainer, animateContainer, moveContainer, collideContainer, actionContainer, gameObjectContainer); });
}

void GameObjectFactory::Register(std::string name, std::function<GameObject*(void)> fn)
{
	//we need to register an instance that already has all of the containers.
	GameObjectFactory::registry.insert({ name, fn });
}

Mike* GameObjectFactory::CreateMike(std::string img_url)
{
	GameObject* instance = GameObjectFactory::Find("mike");
	if (instance != nullptr) {
		Mike* cInstance = dynamic_cast<Mike*>(instance);
		cInstance->Init(img_url);
		gameObjectContainer->AddGameObject(cInstance);
		return cInstance;
	}
	return nullptr;
}
Zombie* GameObjectFactory::CreateZombie()
{
	GameObject* instance = GameObjectFactory::Find("zombie");
	if (instance != nullptr) {
		Zombie* cInstance = dynamic_cast<Zombie*>(instance);
		cInstance->Init();
		gameObjectContainer->AddGameObject(cInstance);
		return cInstance;
	}
	return nullptr;
}

NormalBullet * GameObjectFactory::CreateNormalBullet(PlayableCharacter * obj)
{
	GameObject* instance = GameObjectFactory::Find("bullet");

	if (instance != nullptr) {
		NormalBullet* cInstance = dynamic_cast<NormalBullet*>(instance);
		cInstance->Init(drawContainer, moveContainer, collideContainer, gameObjectContainer);
		cInstance->SetOrigin(obj);//link the behaviour to its gameObject
		cInstance->CalculateEndPoint();
		gameObjectContainer->AddGameObject(cInstance);
		return cInstance;
	}

	return nullptr;
}

MachineGunBullet * GameObjectFactory::CreateMachineGunBullet(PlayableCharacter * obj)
{
	GameObject* instance = GameObjectFactory::Find("MachineGunBullet");

	if (instance != nullptr) {
		MachineGunBullet* cInstance = dynamic_cast<MachineGunBullet*>(instance);
		cInstance->Init(drawContainer, moveContainer, collideContainer, gameObjectContainer);
		cInstance->SetOrigin(obj);//link the behaviour to its gameObject
		gameObjectContainer->AddGameObject(cInstance);
		return cInstance;
	}

	return nullptr;
}

Medkit * GameObjectFactory::CreateMedkit(Character* obj)
{
	GameObject* instance = GameObjectFactory::Find("Medkit");

	if (instance != nullptr) {
		Medkit* cInstance = dynamic_cast<Medkit*>(instance);
		
		cInstance->SetOrigin(obj);//Position the object
		gameObjectContainer->AddGameObject(cInstance);
		return cInstance;
	}

	return nullptr;
}

AmmoBox * GameObjectFactory::CreateAmmoBox(Character * obj)
{
	GameObject* instance = GameObjectFactory::Find("AmmoBox");

	if (instance != nullptr) {
		AmmoBox* cInstance = dynamic_cast<AmmoBox*>(instance);

		cInstance->SetOrigin(obj);//Position the object
		gameObjectContainer->AddGameObject(cInstance);
		return cInstance;
	}

	return nullptr;
}

Pickup * GameObjectFactory::CreateRandomPickup(Character * obj)
{
	Pickup* p = nullptr;
	int dice_roll = NumberUtility::RandomNumber(1, 100);
	const int ammoChance = 10;
	const int medKitChance = 2;
	if (dice_roll <= medKitChance) {
		p = CreateMedkit(obj);
	}
	else if (dice_roll <= ammoChance) {
		p = CreateAmmoBox(obj);
	}
	return p;
}


