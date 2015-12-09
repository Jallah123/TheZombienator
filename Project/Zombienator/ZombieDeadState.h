#pragma once
#include "ZombieState.h"
class ZombieDeadState : public ZombieState
{
public:
	ZombieDeadState();
	~ZombieDeadState();
	void CheckState();
	void Update(float dt);
};

