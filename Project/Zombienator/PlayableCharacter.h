#pragma once
#include "Character.h"
#include "Weapon.h"

class PlayableCharacter
	: public Character
{
private:
	int currentWeaponIndex = 0;
	bool hasWeapon(Weapon* w);
protected:
	std::vector<Weapon*> weapons = {};
	Weapon* weapon = nullptr;
	bool isFlare = false;
public:
	PlayableCharacter();
	virtual ~PlayableCharacter();

	void TakeHit(int damage) override;
	void AddWeapon(Weapon* w);
	Weapon* GetWeapon() { return this->weapon; }
	int const AmountOfWeapons() { return weapons.size(); }
	int const CurrentWeaponIndex() { return currentWeaponIndex; }

	void SetWeapon(Weapon* w);
	void NextWeapon();
	void PreviousWeapon();
	void Teleport(SDL_Renderer* ren);
	void SetFlare(bool newFlare);
};

