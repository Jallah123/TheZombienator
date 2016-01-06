#pragma once
#include "Weapon.h"
class Bazooka :
	public Weapon
{
public:
	Bazooka();
	~Bazooka();

	void Fire() override;
};

