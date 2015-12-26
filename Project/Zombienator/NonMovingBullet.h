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
	virtual void Hit() {};
	int GetDamage() { return this->damage; }
	void SetDamage(int d) { damage = d; }
};

