#pragma once
#include "Weapon.h"
class Mine :
	public Weapon
{
public:
	Mine();
	~Mine();

	void Fire() override;
};

