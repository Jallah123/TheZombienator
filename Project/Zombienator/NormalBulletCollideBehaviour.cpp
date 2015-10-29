#pragma once
#include "Zombie.h"
#include "NormalBulletCollideBehaviour.h"
#include "Bullet.h"
#include "PlayableCharacter.h"
#include "ContainerContainer.h"
#include <iostream>
#include <vector>
NormalBulletCollideBehaviour::~NormalBulletCollideBehaviour()
{
}

bool NormalBulletCollideBehaviour::Collide(float dt)
{
	Bullet* bullet = dynamic_cast<Bullet*>(this->gameObject);
	std::vector<Character*> characters = ContainerContainer::GetInstance().GetCharacterContainer()->GetCharacters();
	for (auto& c : characters)
	{
		Zombie* target = dynamic_cast<Zombie*>(c);
		if (target != nullptr && SDL_HasIntersection(&bullet->GetDestinationRect(), &c->GetDestinationRect()))
		{
			c->TakeHit(bullet->GetOrigin()->GetWeapon()->GetDamage());
			bullet->SetCollision(true);
			bullet->SetTarget(c);
			return true;
		}
	}
	
	return false;
}
