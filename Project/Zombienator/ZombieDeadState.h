#pragma once
#include "ZombieState.h"
class ZombieDeadState : public ZombieState
{
private:
	SoundController* SoundController = &SoundController::GetInstance();
public:
	ZombieDeadState();
	~ZombieDeadState();
	void CheckState();
	void Update(float dt);
	int counter = 80;

	float elapsedTime = 0.0f, totalTime = 120.0f;
};

