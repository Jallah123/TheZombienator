#pragma once
#include "Bullet.h"
class NonMovingBullet :
	public Bullet
{
protected:
	int damage = 0;
public:
	NonMovingBullet();
	~NonMovingBullet();
	int GetDamage() { return damage; };
	virtual void Hit() {};
};

