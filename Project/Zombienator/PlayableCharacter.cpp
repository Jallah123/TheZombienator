#include "PlayableCharacter.h"
#include <algorithm>


PlayableCharacter::PlayableCharacter() : Character()
{
}


PlayableCharacter::~PlayableCharacter()
{
	delete weapon;
}

void PlayableCharacter::AddWeapon(Weapon * w)
{
	weapons.push_back(w);
	if (weapon == nullptr) {
		SetWeapon(w);
	}
}

void PlayableCharacter::SetWeapon(Weapon * w)
{
	this->weapon = w;
	this->weapon->GiveTo(this);
}

void PlayableCharacter::NextWeapon()
{
	int pos = std::find(weapons.begin(), weapons.end(), weapon) - weapons.begin();
	int index = pos == weapons.size() -1 ? 0 : pos + 1;
	SetWeapon(weapons.at(index));
}

void PlayableCharacter::PreviousWeapon()
{
	int pos = std::find(weapons.begin(), weapons.end(), weapon) - weapons.begin();
	int index = pos == 0 ? weapons.size() - 1 : pos - 1;
	SetWeapon(weapons.at(index));
}
