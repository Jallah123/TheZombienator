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
}
