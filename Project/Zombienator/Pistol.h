#pragma once
#include "Weapon.h"
class Pistol :
	public Weapon
{
public:
	Pistol();
	~Pistol();

	virtual void Fire() override;

};

