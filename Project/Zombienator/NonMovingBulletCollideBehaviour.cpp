#include "NonMovingBulletCollideBehaviour.h"
#include "GameObjectContainer.h"
#include "Zombie.h"
#include "NonMovingBullet.h"
NonMovingBulletCollideBehaviour::NonMovingBulletCollideBehaviour() : CollideBehaviour()
{
}


NonMovingBulletCollideBehaviour::~NonMovingBulletCollideBehaviour()
{
}

void NonMovingBulletCollideBehaviour::Collide(float dt)
{
	NonMovingBullet* bullet = dynamic_cast<NonMovingBullet*>(this->gameObject);

	std::vector<GameObject*> gos = gameObjectContainer->GetCollideableObjects();
	for (auto& g : gos)
	{
		if (g != bullet->GetOrigin() && g != bullet) {
			if (SDL_HasIntersection(bullet->GetDestinationRect(), g->GetDestinationRect())) {

				//when a collide happens,get zombie's in triple size radius
				SDL_Rect* radiusR = bullet->GetDestinationRect();
				float radiusX = radiusR->w * 3;
				float radiusY = radiusR->h * 3;
				radiusR->x -= radiusX;
				radiusR->y -= radiusY;
				radiusR->w += radiusX;
				radiusR->h += radiusY;
				for (auto& z : gos) {
					if (SDL_HasIntersection(radiusR, z->GetDestinationRect())) {
						Zombie* target = dynamic_cast<Zombie*>(z);
						if (target != nullptr)
						{
							target->TakeHit(bullet->GetDamage());
							bullet->Hit();
							bullet->ShakeScreen();
							bullet->Remove();
						}
						//check for other player:
						else if (dynamic_cast<PlayableCharacter*>(z) != nullptr && Settings::GetInstance().getFiendlyFire()) {
							PlayableCharacter* pCharachter = dynamic_cast<PlayableCharacter*>(z);
							//check if not player who planted the bullet
							if (bullet->GetOrigin() != pCharachter) {
								pCharachter->TakeHit(bullet->GetDamage());
								bullet->Hit();
								bullet->ShakeScreen();
								bullet->Remove();
							}
						}
					}
				}
				//after full round of collidableobjects checks break from outer loop.
				break;
			}
		}
	}
}
