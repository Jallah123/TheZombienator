#pragma once
#include "CollideBehaviour.h"
class MovingBulletCollideBehaviour :
	public CollideBehaviour
{
public:
	MovingBulletCollideBehaviour();
	~MovingBulletCollideBehaviour();
	virtual void Collide(float dt) override;

};

