#pragma once
#include "ZombieState.h"
class ZombieWalkingState :
	public ZombieState
{
public:
	ZombieWalkingState();
	~ZombieWalkingState();
	void CheckState();
	void Update(float dt);
};

