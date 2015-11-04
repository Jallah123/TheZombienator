#pragma once
#include "AnimateContainer.h"
#include "AnimateBehaviour.h"
#include "BehaviourFactory.h"

AnimateContainer::AnimateContainer()
{
	BehaviourFactory::Instance()->Register("AnimateBehaviour", [](void) -> Behaviour* { return new AnimateBehaviour(); });
}


AnimateContainer::~AnimateContainer()
{
}

void AnimateContainer::Animate(float dt)
{
	if (this->arr.empty()) return;//Do nothing on empty
	Uint32 ticks = SDL_GetTicks();
	for (Behaviour* i : this->arr) {
		AnimateBehaviour* ab = dynamic_cast<AnimateBehaviour*>(i);

		//Draw each Behaviour
		ab->Animate(dt, ticks);
		if (ab->CanBeRemove()) arrRemove.push_back(ab);
	}
	RemoveAll();
}

