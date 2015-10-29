#include "Zombie.h"
#include "CharacterContainer.h"


Zombie::Zombie() : Character() {}


Zombie::~Zombie()
{
}


void Zombie::Init(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, ActionContainer* actionC,CharacterContainer* characterC, SDL_Renderer* ren)
{
	//Zombie doesn't have input from the InputContainer
	this->SetContainers(drawC, animC, moveC, nullptr, nullptr);
	SetDrawBehaviour("CharacterDrawBehaviour");
	SetAnimateBehaviour("AnimateBehaviour");
	SetMoveBehaviour("AiMoveBehaviour");
	characterC->AddCharacter(this);
	SetImage("assets/images/spritesheets/1zombie.png", *ren);
	SetSize(32, 36);
	SetFrames(3);
	SetSpeed(0.2f);
}