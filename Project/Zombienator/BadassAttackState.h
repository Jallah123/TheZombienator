#pragma once
#include "ZombieState.h"
class BadassAttackState :
	public ZombieState
{
public:
	BadassAttackState();
	~BadassAttackState();

	virtual void CheckState() override;
	virtual void Update(float dt) override;
};

