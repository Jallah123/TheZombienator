#pragma once
#include <iostream>
#include <vector>
#include "Zombie.h"
#include "NormalBulletCollideBehaviour.h"
#include "Bullet.h"
#include "PlayableCharacter.h"
#include "CharacterContainer.h"

NormalBulletCollideBehaviour::~NormalBulletCollideBehaviour()
{
}

void NormalBulletCollideBehaviour::Collide(float dt)
{
	Bullet* bullet = dynamic_cast<Bullet*>(this->gameObject);
	

	for (auto& r : this->collisionLayer->GetRects()) {
		if (SDL_HasIntersection(this->gameObject->GetDestinationRect(), r)) {
			bullet->SetCollision(true);
			bullet->SetTarget(r);
		}
	}

	std::vector<Character*> characters = characterContainer->GetCharacters();
	for (auto& c : characters)
	{
		Zombie* target = dynamic_cast<Zombie*>(c);
		if (target != nullptr && SDL_HasIntersection(bullet->GetDestinationRect(), c->GetDestinationRect()))
		{
			c->TakeHit(bullet->GetOrigin()->GetWeapon()->GetDamage());
			bullet->SetCollision(true);
			bullet->SetTarget(c->GetDestinationRect());
		}
	}
}
