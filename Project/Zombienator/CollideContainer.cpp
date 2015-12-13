#include "CollideContainer.h"
#include "CollideBehaviour.h"
#include "BehaviourFactory.h"
#include "NormalBulletCollideBehaviour.h"
#include "Bullet.h"
#include "CharacterCollideBehaviour.h"
#include "MovingBulletCollideBehaviour.h"
#include "PickupCollideBehaviour.h"
CollideContainer::CollideContainer()
{
	BehaviourFactory::Instance()->Register("NormalBulletCollideBehaviour", [](void) -> Behaviour* { return new NormalBulletCollideBehaviour(); });
	BehaviourFactory::Instance()->Register("CharacterCollideBehaviour", [](void) -> Behaviour* { return new CharacterCollideBehaviour(); });
	BehaviourFactory::Instance()->Register("MovingBulletCollideBehaviour", [](void) -> Behaviour* { return new MovingBulletCollideBehaviour(); });
	BehaviourFactory::Instance()->Register("PickupCollideBehaviour", [](void) -> Behaviour* { return new PickupCollideBehaviour(); });
}

CollideContainer::~CollideContainer()
{
}

void CollideContainer::Collide(float dt)
{
	if (arr.empty()) return;

	for (auto& behaviour : arr)
	{
		CollideBehaviour* collideBehaviour = dynamic_cast<CollideBehaviour*>(behaviour);
		collideBehaviour->Collide(dt);

		if(behaviour->CanBeRemove()) arrRemove.push_back(behaviour);
	}
	RemoveAll();
}
