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
			//Zombie* target = dynamic_cast<Zombie*>(g);
			SDL_Point* b = bullet->GetBeginPoint();
			SDL_Point* e = bullet->GetEndPoint();
			if (GameMath::LineIntersectsRect(b, e, g->GetDestinationRect(), bullet->GetMoveDir()))
			{
				collision.push_back(g);
			}
		}
	}

	if (collision.size() > 0) {
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
