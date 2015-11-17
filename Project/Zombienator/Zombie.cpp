#include "Zombie.h"
#include "CharacterContainer.h"
#include "NumberUtility.h"
#include <string>

using std::string;

Zombie::Zombie() : Character() {}


Zombie::~Zombie()
{
}


void Zombie::Init(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, ActionContainer* actionC, CollideContainer* collideC, CharacterContainer* characterC, SDL_Renderer* ren)
{
	//Zombie doesn't have input from the InputContainer	
	int dice_roll = NumberUtility::RandomNumber(1, 6);

	string basePath = "assets/images/spritesheets/";
	string spriteSheet = std::to_string(dice_roll) + "zombie.png";

	SetImage(basePath+spriteSheet, *ren);
	this->SetContainers(drawC, animC, moveC, nullptr, nullptr, collideC, characterC);
	SetDrawBehaviour("CharacterDrawBehaviour");
	SetAnimateBehaviour("AnimateBehaviour");
	SetMoveBehaviour("AiMoveBehaviour");
	SetCollideBehaviour("CharacterCollideBehaviour");

	characterC->AddCharacter(this);
	
	SetSize(32, 36);
	SetFrames(3);
	SetSpeed(0.2f);
	SetHealth(50);
}