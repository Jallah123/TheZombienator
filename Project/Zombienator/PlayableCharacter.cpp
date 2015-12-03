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

void PlayableCharacter::Teleport(SDL_Renderer* ren) {

	if (!this->isFlare) {
		SetFlare(true);
		this->Remove();
		// Set flare
		SetImage("assets/images/flare.png", *ren);
	}

	SetSize(256, 256);
	SetPosition(getPosX(), getPosY() - 3);
}

void PlayableCharacter::SetFlare(bool newFlare) {

	if(newFlare){
		CanMove(false);
		SetPosition(getPosX() - 100, getPosY() - 100);
		isFlare = true;
	}
	else {
		CanMove(true);
		isFlare = false;
	}

}