#pragma once
#include "CharacterContainer.h"
#include "GameObjectFactory.h"
#include "Mike.h"
#include "Zombie.h"
#include "GameObject.h"

CharacterContainer::CharacterContainer()
{	
}

void CharacterContainer::Init()
{
	GameObjectFactory::Instance()->Register("mike", [](void) -> GameObject* {return new Mike(); });
	GameObjectFactory::Instance()->Register("zombie", [](void) -> GameObject* {return new Zombie(); });
}

CharacterContainer::~CharacterContainer()
{
	std::vector<Character*>::reverse_iterator it;
	for (it = characters.rbegin(); it != characters.rend(); ++it)
		delete *it;

	characters.clear();

	for (it = arrRemove.rbegin(); it != arrRemove.rend(); ++it)
		delete *it;

	arrRemove.clear();
}
