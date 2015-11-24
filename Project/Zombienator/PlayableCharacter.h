#pragma once
#include "Character.h"
#include "Weapon.h"
class PlayableCharacter
	: public Character
{
protected:
	std::vector<Weapon*> weapons = {};
	Weapon* weapon = nullptr;

public:
	PlayableCharacter();
	virtual ~PlayableCharacter();

	void AddWeapon(Weapon* w);
	Weapon* GetWeapon() { return this->weapon; }
	void SetWeapon(Weapon* w);
	void NextWeapon();
	void PreviousWeapon();
};

