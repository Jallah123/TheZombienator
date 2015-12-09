#include "Mike.h"
#include "KeyboardInputHandler.h"
#include "Pistol.h"
#include "MachineGun.h"
#include "GameObjectContainer.h"
#include "DrawContainer.h"

Mike::Mike()
	: PlayableCharacter()
{
}

Mike::Mike(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, CollideContainer * collideC, ActionContainer * actionC, GameObjectContainer * gameObjectC)
	: PlayableCharacter(drawC, animC, moveC, collideC, actionC, gameObjectC)
{
}

void Mike::Init(string img_url)
{
	KeyboardInputHandler& kh = KeyboardInputHandler::GetInstance();
	inputContainer = kh.inputContainer;
	
	this->AddWeapon(new MachineGun());
	this->AddWeapon(new Pistol());

	SetDrawBehaviour("CharacterDrawBehaviour");
	SetAnimateBehaviour("AnimateBehaviour");
	SetMoveBehaviour("PcMoveBehaviour");
	SetActionBehaviour("ShootActionBehaviour");
	SetActionBehaviour("SwitchWeaponActionBehaviour");
	SetCollideBehaviour("CharacterCollideBehaviour");

	gameObjectContainer->AddGameObject(this);

	SetImage(img_url);
	SetSize(36, 38);
	SetFrames(3);
	SetMaxHealth(50);
	SetHealth(50);
}

Mike::~Mike()
{
}
