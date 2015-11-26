#pragma once
#include "Character.h"
#include "Weapon.h"

class PlayableCharacter
	: public Character
{
protected:
	Weapon* weapon;
public:
	PlayableCharacter();
	virtual ~PlayableCharacter();
	Weapon* GetWeapon() { return this->weapon; }
	void SetWeapon(Weapon* w) { 
		this->weapon = w; 
		this->weapon->GiveTo(this);
	}
};

