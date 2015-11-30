#pragma once
#include "ZombieState.h"
class ZombieStandStillState :
	public ZombieState
{
public:
	ZombieStandStillState();
	~ZombieStandStillState();
	void CheckState();
	void Update(float dt);
};

