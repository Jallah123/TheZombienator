#include "CollideContainer.h"
#include "CollideBehaviour.h"
#include "BehaviourFactory.h"

#include "NormalBulletCollideBehaviour.h"
#include "NonMovingBulletCollideBehaviour.h"
#include "CharacterCollideBehaviour.h"
#include "MovingBulletCollideBehaviour.h"
#include "PickupCollideBehaviour.h"

CollideContainer::CollideContainer()
{
	BehaviourFactory::Instance()->Register("NormalBulletCollideBehaviour", [](void) -> Behaviour* { return new NormalBulletCollideBehaviour(); });
	BehaviourFactory::Instance()->Register("CharacterCollideBehaviour", [](void) -> Behaviour* { return new CharacterCollideBehaviour(); });
	BehaviourFactory::Instance()->Register("MovingBulletCollideBehaviour", [](void) -> Behaviour* { return new MovingBulletCollideBehaviour(); });
	BehaviourFactory::Instance()->Register("PickupCollideBehaviour", [](void) -> Behaviour* { return new PickupCollideBehaviour(); });
	BehaviourFactory::Instance()->Register("NonMovingBulletCollideBehaviour", [](void) -> Behaviour* { return new NonMovingBulletCollideBehaviour(); });
}

CollideContainer::~CollideContainer()
{
}

void CollideContainer::Collide(float dt)
{
	if (arr.empty()) return;

	for (auto itr = arr.begin(); itr != arr.end();)
	{
		CollideBehaviour* collideBehaviour = dynamic_cast<CollideBehaviour*>(*itr);
		collideBehaviour->Collide(dt);

		if (collideBehaviour->CanBeRemove())
			itr = Remove(collideBehaviour);
		else
			++itr;
	}
}
