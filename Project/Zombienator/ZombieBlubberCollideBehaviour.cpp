#include "ZombieBlubberCollideBehaviour.h"
#include "ZombieBlubberBullet.h"
#include "Zombie.h"
#include "GameObjectContainer.h"

ZombieBlubberCollideBehaviour::ZombieBlubberCollideBehaviour()
{
}


ZombieBlubberCollideBehaviour::~ZombieBlubberCollideBehaviour()
{
}

void ZombieBlubberCollideBehaviour::Collide(float dt)
{
	ZombieBlubberBullet* bullet = static_cast<ZombieBlubberBullet*>(this->gameObject);
	Zombie* bz = static_cast<Zombie*>(bullet->GetOrigin());
	std::vector<GameObject*> gos = gameObjectContainer->GetCollideableObjects();
	for (auto& g : gos)
	{
		if (gameObject != g && g != bullet->GetOrigin()) {//cannot collide itself or its owner

			if (SDL_HasIntersection(bullet->GetDestinationRect(), g->GetDestinationRect())) {
				Character* target = dynamic_cast<Character*>(g);

				if (target != nullptr)
				{
					target->TakeHit(bz->GetAttackDamage());
				}

				bullet->Remove();
			}
		}
	}
}
