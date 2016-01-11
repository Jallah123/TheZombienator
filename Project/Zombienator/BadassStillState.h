#pragma once
#include "ZombieState.h"
class BadassStillState :
	public ZombieState
{
public:
	BadassStillState();
	~BadassStillState();

	virtual void CheckState() override;
	virtual void Update(float dt) override;
};

