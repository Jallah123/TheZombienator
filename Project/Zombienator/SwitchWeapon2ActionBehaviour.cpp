#include "SwitchWeapon2ActionBehaviour.h"
#include "PlayableCharacter.h"
#include "InputContainer.h"


SwitchWeapon2ActionBehaviour::SwitchWeapon2ActionBehaviour()
{
	action = SDLK_DELETE;
	actionBackward = SDLK_PAGEDOWN;
}


SwitchWeapon2ActionBehaviour::~SwitchWeapon2ActionBehaviour()
{

}

void SwitchWeapon2ActionBehaviour::Update(float dt)
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
