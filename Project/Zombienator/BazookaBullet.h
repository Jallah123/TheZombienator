#pragma once
#include "Bullet.h"
class BazookaBullet :
	public Bullet
{
public:
	BazookaBullet();
	~BazookaBullet();

	virtual void SetBehaviours() override;
	virtual void ShakeScreen() override;
};

