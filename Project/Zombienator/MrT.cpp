#include "MrT.h"
#include "KeyboardInputHandler.h"
#include "Pistol.h"
#include "MachineGun.h"
#include "GameObjectContainer.h"
#include "DrawContainer.h"

MrT::MrT() : PlayableCharacter()
{
}

void MrT::Init(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, ActionContainer* actionC, CollideContainer* collideC, GameObjectContainer* gameObjectC, SDL_Renderer* ren, string img_url)
{
	KeyboardInputHandler& kh = KeyboardInputHandler::GetInstance();
	this->SetContainers(drawC, animC, moveC, kh.inputContainer, actionC, collideC, gameObjectC);

	this->AddWeapon(new MachineGun());
	this->AddWeapon(new Pistol());

	SetDrawBehaviour("CharacterDrawBehaviour");
	SetAnimateBehaviour("AnimateBehaviour");
	SetMoveBehaviour("Pc2MoveBehaviour");
	SetActionBehaviour("Shoot2ActionBehaviour");
	SetActionBehaviour("SwitchWeapon2ActionBehaviour");
	SetCollideBehaviour("CharacterCollideBehaviour");

	gameObjectC->AddGameObject(this);

	SetImage(img_url, *ren);
	SetSize(36, 38);
	SetFrames(3);
	SetMaxHealth(50);
	SetHealth(50);
}

MrT::~MrT()
{
}
