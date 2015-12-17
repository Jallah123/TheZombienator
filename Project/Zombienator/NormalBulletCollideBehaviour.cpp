#pragma once
#include "NormalBulletCollideBehaviour.h"
#include <vector>
#include <math.h>
#include "Zombie.h"
#include "NormalBullet.h"
#include "GameObjectContainer.h"
#include "GameMath.h"

NormalBulletCollideBehaviour::~NormalBulletCollideBehaviour()
{
}

void NormalBulletCollideBehaviour::Collide(float dt)
{
	NormalBullet* bullet = dynamic_cast<NormalBullet*>(this->gameObject);
	if (bullet->HasCollision()) return;
	std::vector<GameObject*> gos = gameObjectContainer->GetGameObjects();
	std::vector<GameObject*> collision = {};
	for (auto& g : gos)
	{
		if (g != bullet->GetOrigin() && g != bullet) {
			SDL_Point* b = bullet->GetBeginPoint();
			SDL_Point* e = bullet->GetEndPoint();
			if(SDL_IntersectRectAndLine(g->GetDestinationRect(), &b->x, &b->y, &e->x, &e->y))
			{
				collision.push_back(g);
			}
		}
	}

	if (collision.size() > 0) {
		HandleClosest( GetClosest(collision, *bullet), bullet );
	}
	CanRemove(true);
}

GameObject * NormalBulletCollideBehaviour::GetClosest(std::vector<GameObject*> objects, GameObject & origin)
{
	GameObject* closest = nullptr;
	double lastDist = INT_MAX;
	for (auto& g : objects) {
		double dist = GameMath::Distance(origin, *g);
		if (dist < lastDist)
		{
			closest = g;
			lastDist = dist;
		}
	}
	return closest;
}

void NormalBulletCollideBehaviour::HandleClosest(GameObject * closest, Bullet* bullet)
{
	if (closest != nullptr) {
		Zombie* zombie = dynamic_cast<Zombie*>(closest);
		bullet->SetTarget(closest);

		if (zombie != nullptr) {
			zombie->TakeHit(bullet->GetOrigin()->GetWeapon()->GetDamage());
		}
		//check if object is playableCharacter
		else if(dynamic_cast<PlayableCharacter*>(closest) != nullptr && Settings::GetInstance().getFiendlyFire()) {
			PlayableCharacter* pCharachter = dynamic_cast<PlayableCharacter*>(closest);
			pCharachter->TakeHit(bullet->GetOrigin()->GetWeapon()->GetDamage());
		}

		bullet->SetCollision(true);
		
	}
}


