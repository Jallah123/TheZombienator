#pragma once
#include "Bullet.h"
class MachineGunBullet :
	public Bullet
{
public:
	MachineGunBullet();
	~MachineGunBullet();

	virtual void SetBehaviours() override;
};

