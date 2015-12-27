#include "PlayableCharacter.h"
#include "Settings.h"
#include <algorithm>
#include "KeyboardInputHandler.h"
#include "Pistol.h"
#include "MachineGun.h"
#include "GameObjectContainer.h"
#include "DrawContainer.h"

PlayableCharacter::PlayableCharacter() : Character()
{
}

PlayableCharacter::PlayableCharacter(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, CollideContainer * collideC, ActionContainer * actionC, GameObjectContainer * gameObjectC)
	: Character(drawC, animC, moveC, collideC, actionC, gameObjectC)
{
}

PlayableCharacter::~PlayableCharacter()
{
	for (auto& w : weapons)
		delete w;

	weapons.clear();
	delete weapon;
	delete keyBinding;
}

void PlayableCharacter::Init(string img_url, KeyBinding* _keyBinding)
{
		KeyboardInputHandler& kh = KeyboardInputHandler::GetInstance();

		keyBinding = _keyBinding;

		this->AddWeapon(new MachineGun());
		this->AddWeapon(new Pistol());

		SetDrawBehaviour("CharacterDrawBehaviour");
		SetAnimateBehaviour("AnimateBehaviour");
		SetMoveBehaviour("PcMoveBehaviour");
		SetActionBehaviour("ShootActionBehaviour");
		SetActionBehaviour("SwitchWeaponActionBehaviour");
		SetCollideBehaviour("CharacterCollideBehaviour");

		SetImage(img_url);
		SetSize(36, 38);
		SetFrames(3);
		SetMaxHealth(50);
		SetHealth(50);
}

bool PlayableCharacter::hasWeapon(Weapon* w)
{
	for each (auto weapon in weapons)
	{
		if (w->GetName() == weapon->GetName())
			return true;
	}
	return false;
}

void PlayableCharacter::AddWeapon(Weapon * w)
{
	if (hasWeapon(w))
		return;
	weapons.push_back(w);
	if (weapon == nullptr) {
		SetWeapon(w);
	}
}

void PlayableCharacter::TakeHit(int damage)
{
	if(!Settings::GetInstance().getGodMode())
	{
		Character::TakeHit(damage);
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
	currentWeaponIndex = pos == weapons.size() -1 ? 0 : pos + 1;
	SetWeapon(weapons.at(currentWeaponIndex));
}

void PlayableCharacter::PreviousWeapon()
{
	int pos = std::find(weapons.begin(), weapons.end(), weapon) - weapons.begin();
	currentWeaponIndex = pos == 0 ? weapons.size() - 1 : pos - 1;
	SetWeapon(weapons.at(currentWeaponIndex));
}

void PlayableCharacter::Teleport(SDL_Renderer* ren) {

	if (!this->isFlare) {
		SetFlare(true);
		this->Remove();
		// Set flare
		SetImage("assets/images/flare.png");
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