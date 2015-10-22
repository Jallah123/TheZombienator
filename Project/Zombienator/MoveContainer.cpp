#pragma once
#include "MoveContainer.h"
#include "MoveBehaviour.h"
#include "BehaviourFactory.h"


MoveContainer::MoveContainer()
{
	BehaviourFactory::Instance()->Register("MoveBehaviour", [](void) -> Behaviour* { return new MoveBehaviour(); });
}


MoveContainer::~MoveContainer()
{
}

void MoveContainer::Move(float dt)
{
	if (this->arr.empty()) return;//Do nothing on empty
	Uint32 ticks = SDL_GetTicks();
	for (Behaviour* i : this->arr) {
		MoveBehaviour* mb = dynamic_cast<MoveBehaviour*>(i);
	
		//Draw each Behaviour
		mb->Move(dt, ticks, inputContainer);
	}
}

