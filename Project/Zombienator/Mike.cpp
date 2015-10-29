#include "Mike.h"
#include "KeyboardInputHandler.h"
#include "Pistol.h"
#include "CharacterContainer.h"

Mike::Mike() : PlayableCharacter(){}

void Mike::Init(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, ActionContainer* actionC, CharacterContainer* characterC, SDL_Renderer* ren)
{
	KeyboardInputHandler& kh = KeyboardInputHandler::GetInstance();
	this->SetContainers(drawC, animC, moveC, kh.inputContainer, actionC);

	this->SetWeapon(new Pistol());
	
	SetDrawBehaviour("CharacterDrawBehaviour");
	SetAnimateBehaviour("AnimateBehaviour");
	SetMoveBehaviour("PcMoveBehaviour");
	SetActionBehaviour("ShootActionBehaviour");

	characterC->AddCharacter(this);

	SetImage("assets/images/spritesheets/Boy1.png", *ren);
	SetSize(36, 38);
	SetFrames(3);
}


Mike::~Mike()
{
}
