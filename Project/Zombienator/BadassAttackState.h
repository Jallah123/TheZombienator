#pragma once
#include "ZombieState.h"
class BadassAttackState :
	public ZombieState
{
private:
	float elapsedTime = 0;
	int shootDelay = 150;
public:
	BadassAttackState();
	~BadassAttackState();

	virtual void CheckState() override;
	virtual void Update(float dt) override;
};

