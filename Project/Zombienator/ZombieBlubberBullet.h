#pragma once
#include "Bullet.h"
class ZombieBlubberBullet :
	public Bullet
{
public:
	ZombieBlubberBullet();
	~ZombieBlubberBullet();

	virtual void SetBehaviours() override;

};

