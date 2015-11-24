#include "MovingBulletCollideBehaviour.h"
#include "GameObjectContainer.h"
#include "Zombie.h"
#include "Bullet.h"
MovingBulletCollideBehaviour::MovingBulletCollideBehaviour()
{
}


MovingBulletCollideBehaviour::~MovingBulletCollideBehaviour()
{
}

void MovingBulletCollideBehaviour::Collide(float dt)
{
	Bullet* bullet = dynamic_cast<Bullet*>(this->gameObject);

	std::vector<GameObject*> gos = gameObjectContainer->GetGameObjects(gameObject->getPosX(), gameObject->getPosY());
	for (auto& g : gos)
	{
		if (g != bullet->GetOrigin()) {
			Zombie* target = dynamic_cast<Zombie*>(g);
			if (SDL_HasIntersection(gameObject->GetDestinationRect(), g->GetDestinationRect())) {
				if (target != nullptr)
				{
					target->TakeHit(bullet->GetOrigin()->GetWeapon()->GetDamage());
				}
				bullet->Remove();
			}
		}
	}
}
