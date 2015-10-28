#include "CollideContainer.h"
#include "CollideBehaviour.h"
#include "BehaviourFactory.h"
#include "NormalBulletCollideBehaviour.h"

CollideContainer::CollideContainer()
{
	BehaviourFactory::Instance()->Register("NormalBulletCollideBehaviour", [](void) -> Behaviour* { return new NormalBulletCollideBehaviour(); });
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
	}
}
