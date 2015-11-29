#pragma once
#include "Weapon.h"
class MachineGun :
	public Weapon
{
public:
	MachineGun();
	~MachineGun();

	virtual void Fire() override;
};

