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

	std::vector<GameObject*> gos = gameObjectContainer->GetGameObjects();
	for (auto& g : gos)
	{
		if (g != bullet->GetOrigin() && g != bullet) {
			if (SDL_HasIntersection(bullet->GetDestinationRect(), g->GetDestinationRect())) {
				Character* target = dynamic_cast<Character*>(g);
				if (target != nullptr)
				{
					target->TakeHit(bullet->GetOrigin()->GetWeapon()->GetDamage());

					//check if object is playableCharacter
					if (dynamic_cast<PlayableCharacter*>(g) != nullptr && Settings::GetInstance().getFiendlyFire()) {
						PlayableCharacter* pCharachter = dynamic_cast<PlayableCharacter*>(g);
						pCharachter->TakeHit(bullet->GetOrigin()->GetWeapon()->GetDamage());
					}
				}
				bullet->Remove();
			}
		}
	}
}
