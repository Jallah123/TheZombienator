#ifndef ANIMATE_BEHAVIOUR_H
#define ANIMATE_BEHAVIOUR_H

#pragma once
#include "Behaviour.h"
#include "Character.h"

class AnimateBehaviour :
	public Behaviour
{
public:
	AnimateBehaviour();
	~AnimateBehaviour();

	//Use Animate
	void Animate(float dt, int ticks);
};

#endif