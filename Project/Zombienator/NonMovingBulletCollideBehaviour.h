#pragma once
#include "CollideBehaviour.h"
class NonMovingBulletCollideBehaviour :
	public CollideBehaviour
{
public:
	NonMovingBulletCollideBehaviour();
	~NonMovingBulletCollideBehaviour();
	virtual void Collide(float dt) override;

};

