#pragma once
#include "NonMovingBullet.h"
class MineBullet :
	public NonMovingBullet
{
public:
	MineBullet();
	~MineBullet();
	virtual void SetBehaviours() override;
	virtual void Hit() override;
};

