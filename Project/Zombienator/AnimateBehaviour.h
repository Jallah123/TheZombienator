#pragma once
#include "Behaviour.h"
#include "Character.h"

class AnimateBehaviour : public Behaviour
{
private:
	Uint32 old_time, current_time;
	int currentFrame = 0;
	float timeSinceLastFrameSwap = 0.0f, animationSpeed = 10.0f, ftime;
public:
	AnimateBehaviour();
	~AnimateBehaviour();

	//Use Animate
	void Animate(float dt, int ticks);
};