#pragma once
#include "ZombieState.h"
class ZombieWalkingState :
	public ZombieState
{
public:
	ZombieWalkingState();
	~ZombieWalkingState();

	virtual void CheckState() override;
	virtual void Update(float dt) override;
};

