#pragma once
#include "ZombieState.h"
class BadassWalkingState :
	public ZombieState
{
public:
	BadassWalkingState();
	~BadassWalkingState();

	virtual void CheckState() override;
	virtual void Update(float dt) override;
};

