#pragma once
#include "Weapon.h"
class MachineGun :
	public Weapon
{
public:
	MachineGun();
	~MachineGun();

	void Fire() override;
};

