#pragma once
#include "MoveContainer.h"
#include "MoveBehaviour.h"
#include "BehaviourFactory.h"
#include "PcMoveBehaviour.h"
#include "CollideBehaviour.h"
#include "BulletMoveBehaviour.h"

MoveContainer::MoveContainer()
{
	BehaviourFactory::Instance()->Register("PcMoveBehaviour", [](void) -> Behaviour* { return new PcMoveBehaviour(); });
	BehaviourFactory::Instance()->Register("BulletMoveBehaviour", [](void) -> Behaviour* { return new BulletMoveBehaviour(); });
}

MoveContainer::~MoveContainer()
{
}

void MoveContainer::Move(float dt)
{
	if (this->arr.empty()) return;//Do nothing on empty

	for (auto itr = arr.begin(); itr != arr.end();)
	{
		MoveBehaviour* mb = static_cast<MoveBehaviour*>(*itr);
		mb->Move(dt);

		if (mb->CanBeRemove())
			itr = Remove(mb);
		else
			++itr;
	}
}

