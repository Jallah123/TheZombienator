#pragma once
#include "CollideBehaviour.h"
class ZombieBlubberCollideBehaviour :
	public CollideBehaviour
{
public:
	ZombieBlubberCollideBehaviour();
	~ZombieBlubberCollideBehaviour();

	virtual void Collide(float dt) override;

};

