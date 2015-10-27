#pragma once
#include "MoveContainer.h"
#include "MoveBehaviour.h"
#include "BehaviourFactory.h"
#include "AiMoveBehaviour.h"
#include "PcMoveBehaviour.h"

MoveContainer::MoveContainer()
{
	BehaviourFactory::Instance()->Register("MoveBehaviour", [](void) -> Behaviour* { return new PcMoveBehaviour(); });
	BehaviourFactory::Instance()->Register("AiMoveBehaviour", [](void) -> Behaviour* { return new AiMoveBehaviour(); });
}


MoveContainer::~MoveContainer()
{
}

void MoveContainer::Move(float dt)
{
	if (this->arr.empty()) return;//Do nothing on empty
	for (Behaviour* i : this->arr) {
		MoveBehaviour* mb = dynamic_cast<MoveBehaviour*>(i);
	
		//Draw each Behaviour
		mb->Move(dt);
	}
}

