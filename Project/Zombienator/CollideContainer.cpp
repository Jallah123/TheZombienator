#include "CollideContainer.h"
#include "CollideBehaviour.h"
#include "BehaviourFactory.h"
#include "NormalBulletCollideBehaviour.h"
#include "Bullet.h"
#include "CharacterCollideBehaviour.h"

CollideContainer::CollideContainer()
{
	BehaviourFactory::Instance()->Register("NormalBulletCollideBehaviour", [](void) -> Behaviour* { return new NormalBulletCollideBehaviour(); });
	BehaviourFactory::Instance()->Register("CharacterCollideBehaviour", [](void) -> Behaviour* { return new CharacterCollideBehaviour(); });
}

CollideContainer::~CollideContainer()
{
}

void CollideContainer::Collide(float dt)
{
	for (auto& behaviour : arr)
	{
		CollideBehaviour* collideBehaviour = dynamic_cast<CollideBehaviour*>(behaviour);
		collideBehaviour->Collide(dt);

		if (Bullet* bullet = dynamic_cast<Bullet*>(behaviour->GetGameObject())) {
			if (bullet->GetLifeTime() <= 0 || bullet->HasCollision()) {
				behaviour->CanRemove(true);
			}
		}
		if(behaviour->CanBeRemove()) arrRemove.push_back(behaviour);
	}
	RemoveAll();
}
