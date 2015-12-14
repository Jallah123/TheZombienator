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
	if (arr.empty()) return;//Do nothing on empty

	Uint32 ticks = SDL_GetTicks();
	for (auto itr = arr.begin(); itr != arr.end();)
	{
		AnimateBehaviour* ab = dynamic_cast<AnimateBehaviour*>(*itr);
		ab->Animate(dt, ticks);
		
		if (ab->CanBeRemove())
			itr = Remove(ab);
		else
			++itr;
	}
}

