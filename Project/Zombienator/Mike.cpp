#include "Mike.h"
#include "KeyboardInputHandler.h"
#include "Pistol.h"
#include "MachineGun.h"
#include "GameObjectContainer.h"
#include "DrawContainer.h"
#include "HudDrawBehaviour.h"

Mike::Mike() : PlayableCharacter()
{
}

void Mike::Init(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, ActionContainer* actionC, CollideContainer* collideC, GameObjectContainer* gameObjectC, SDL_Renderer* ren)
{
	KeyboardInputHandler& kh = KeyboardInputHandler::GetInstance();
	this->SetContainers(drawC, animC, moveC, kh.inputContainer, actionC, collideC, gameObjectC);

	this->AddWeapon(new MachineGun());
	this->AddWeapon(new Pistol());
	
	SetDrawBehaviour("CharacterDrawBehaviour");
	SetAnimateBehaviour("AnimateBehaviour");
	SetMoveBehaviour("PcMoveBehaviour");
	SetActionBehaviour("ShootActionBehaviour");
	SetActionBehaviour("SwitchWeaponActionBehaviour");
	SetCollideBehaviour("CharacterCollideBehaviour");

	gameObjectC->AddGameObject(this);

	SetImage("assets/images/spritesheets/Boy1.png", *ren);
	SetSize(36, 38);
	SetFrames(3);
	SetMaxHealth(50);
	SetHealth(50);
	drawContainer->Add(new HudDrawBehaviour{this});
}


Mike::~Mike()
{
}
