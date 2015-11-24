#pragma once
#include "MoveBehaviour.h"
class BulletMoveBehaviour :
	public MoveBehaviour
{
public:
	BulletMoveBehaviour();
	~BulletMoveBehaviour();

	virtual void Move(float dt) override;

};

