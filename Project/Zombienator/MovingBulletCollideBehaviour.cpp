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
		if (g != bullet->GetOrigin() && g != bullet) {
			if (SDL_HasIntersection(bullet->GetDestinationRect(), g->GetDestinationRect())) {
				Zombie* target = dynamic_cast<Zombie*>(g);
				if (target != nullptr)
				{
					target->TakeHit(bullet->GetOrigin()->GetWeapon()->GetDamage());
				}
				bullet->Remove();
			}
		}
	}
}