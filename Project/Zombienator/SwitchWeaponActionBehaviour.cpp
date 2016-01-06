#include "SwitchWeaponActionBehaviour.h"
#include "PlayableCharacter.h"
#include "InputContainer.h"


SwitchWeaponActionBehaviour::SwitchWeaponActionBehaviour()
{

}


SwitchWeaponActionBehaviour::~SwitchWeaponActionBehaviour()
{

}

void SwitchWeaponActionBehaviour::Init()
{
	PlayableCharacter* c = static_cast<PlayableCharacter*>(this->gameObject);
	action = c->getKeyBinding()->PREVIOUSWEAPON;
	actionBackward = c->getKeyBinding()->NEXTWEAPON;
}

void SwitchWeaponActionBehaviour::Update(float dt)
{
	if (!this->gameObject) return;
	PlayableCharacter* c = static_cast<PlayableCharacter*>(this->gameObject);
	InputContainer* iC = c->GetInputContainer();
	if (iC == nullptr) return;

	bool switchForward = iC->GetKeyState(this->action);
	bool switchBackward = iC->GetKeyState(this->actionBackward);
	Weapon* w = c->GetWeapon();
	if (!isPressed) {
		if (switchForward || switchBackward) isPressed = true;
		if (switchForward) {
			c->NextWeapon();
		}
		else if (switchBackward) {
			c->PreviousWeapon();
		}
	}

	if (!switchForward && !switchBackward) isPressed = false;

}
