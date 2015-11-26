#pragma once
#include "ZombieState.h"
class ZombieAttackState :
	public ZombieState
{
public:
	ZombieAttackState();
	~ZombieAttackState();
	void CheckState();
	void Update(float dt);
};

