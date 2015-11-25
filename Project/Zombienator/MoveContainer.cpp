#pragma once
#include "MoveContainer.h"
#include "MoveBehaviour.h"
#include "BehaviourFactory.h"
#include "PcMoveBehaviour.h"
#include "CollideBehaviour.h"

MoveContainer::MoveContainer()
{
	BehaviourFactory::Instance()->Register("PcMoveBehaviour", [](void) -> Behaviour* { return new PcMoveBehaviour(); });
}


MoveContainer::~MoveContainer()
{
}

void MoveContainer::Move(float dt)
{
	if (this->arr.empty()) return;//Do nothing on empty
	for (Behaviour* i : this->arr) {
		MoveBehaviour* mb = static_cast<MoveBehaviour*>(i);

		//Draw each Behaviour
		if (mb) {
			mb->Move(dt);
			if (i->CanBeRemove()) arrRemove.push_back(i);
		}
	}
	RemoveAll();
}

