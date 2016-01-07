#include "MovingBulletCollideBehaviour.h"
#include "GameObjectContainer.h"
#include "Zombie.h"
#include "Bullet.h"

MovingBulletCollideBehaviour::MovingBulletCollideBehaviour() : CollideBehaviour()
{
}

MovingBulletCollideBehaviour::~MovingBulletCollideBehaviour() 
{
}

void MovingBulletCollideBehaviour::Collide(float dt)
{
	Bullet* bullet = dynamic_cast<Bullet*>(this->gameObject);

	std::vector<GameObject*> gos = gameObjectContainer->GetCollideableObjects();
	for (auto& g : gos)
	{
		if (dynamic_cast<PlayableCharacter*>(g)) continue;
		if (g != bullet->GetOrigin() && g != bullet) {
			if (SDL_HasIntersection(bullet->GetDestinationRect(), g->GetDestinationRect())) {
				Zombie* target = dynamic_cast<Zombie*>(g);

				if (target != nullptr)
				{
					target->TakeHit(bullet->GetOrigin()->GetWeapon()->GetDamage());
					bullet->ShakeScreen();
				}
				//check if object is playableCharacter
				else if (dynamic_cast<PlayableCharacter*>(g) != nullptr && Settings::GetInstance().getFiendlyFire()) {
					PlayableCharacter* pCharachter = dynamic_cast<PlayableCharacter*>(g);
					pCharachter->TakeHit(bullet->GetOrigin()->GetWeapon()->GetDamage());
				}

				bullet->Remove();
			}
		}
	}
}
