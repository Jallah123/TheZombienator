#pragma once
#include "CollideBehaviour.h"
class PickupCollideBehaviour
	: public CollideBehaviour
{
public:
	PickupCollideBehaviour();
	~PickupCollideBehaviour();

	virtual void Collide(float dt) override;
};

