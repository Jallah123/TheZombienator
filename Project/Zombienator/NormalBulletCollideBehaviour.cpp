#pragma once
#include <vector>
#include "Zombie.h"
#include "NormalBulletCollideBehaviour.h"
#include "Bullet.h"
#include "PlayableCharacter.h"
#include "GameObjectContainer.h"

NormalBulletCollideBehaviour::~NormalBulletCollideBehaviour()
{
}

void NormalBulletCollideBehaviour::Collide(float dt)
{
	Bullet* bullet = dynamic_cast<Bullet*>(this->gameObject);
		
	std::vector<GameObject*> gos = gameObjectContainer->GetGameObjects();
	for (auto& g : gos)
	{
		Zombie* target = dynamic_cast<Zombie*>(g);
		if (target != nullptr && SDL_HasIntersection(bullet->GetDestinationRect(), g->GetDestinationRect()))
		{
			target->TakeHit(bullet->GetOrigin()->GetWeapon()->GetDamage());
			bullet->SetCollision(true);
			bullet->SetTarget(g->GetDestinationRect());
			return;
		}
	}
}
