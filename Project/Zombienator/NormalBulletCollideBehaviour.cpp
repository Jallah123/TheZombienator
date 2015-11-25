#pragma once
#include <vector>
#include <math.h>
#include "Zombie.h"
#include "NormalBulletCollideBehaviour.h"
#include "NormalBullet.h"
#include "PlayableCharacter.h"
#include "GameObjectContainer.h"
#include <SDL_rect.h>

NormalBulletCollideBehaviour::~NormalBulletCollideBehaviour()
{
}

void NormalBulletCollideBehaviour::Collide(float dt)
{
	NormalBullet* bullet = dynamic_cast<NormalBullet*>(this->gameObject);
		
	std::vector<GameObject*> gos = gameObjectContainer->GetGameObjects();
	std::vector<GameObject*> collision = {};
	for (auto& g : gos)
	{
		//Zombie* target = dynamic_cast<Zombie*>(g);
		SDL_Point* b = bullet->GetBeginPoint();
		SDL_Point* e = bullet->GetEndPoint();
		if(SDL_IntersectRectAndLine(g->GetDestinationRect(), &b->x, &b->y, &e->x, &e->y ))
		//if (SDL_HasIntersection(bullet->GetDestinationRect(), g->GetDestinationRect()))
		{
			collision.push_back(g);
		}
	}
	GameObject* closest = GetClosest(collision, *bullet);
	if (closest != nullptr) {
		Zombie* zombie = dynamic_cast<Zombie*>(closest);
		if (zombie != nullptr) {
			zombie->TakeHit(bullet->GetOrigin()->GetWeapon()->GetDamage());
		}
		bullet->SetCollision(true);
		bullet->SetTarget(closest->GetDestinationRect());
	}
}

GameObject * NormalBulletCollideBehaviour::GetClosest(std::vector<GameObject*> objects, GameObject & origin)
{
	GameObject* closest = nullptr;
	double lastDist = INT_MAX;
	for (auto& g : objects) {
		double newDist = sqrt(pow(origin.getPosX() - g->getPosX(), 2) + pow(origin.getPosY() - g->getPosY(), 2));
		if (newDist < lastDist)
		{
			closest = g;
			lastDist = newDist;
		}
	}
	return closest;
}
