#include "Zombie.h"
#include "CharacterContainer.h"


Zombie::Zombie() : Character() {}


Zombie::~Zombie()
{
}


void Zombie::Init(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, ActionContainer* actionC, CollideContainer* collideC, CharacterContainer* characterC, SDL_Renderer* ren)
{
	//Zombie doesn't have input from the InputContainer
	SetImage("assets/images/spritesheets/1zombie.png", *ren);
	this->SetContainers(drawC, animC, moveC, nullptr, nullptr, collideC, characterC);
	SetDrawBehaviour("CharacterDrawBehaviour");
	SetAnimateBehaviour("AnimateBehaviour");
	SetMoveBehaviour("AiMoveBehaviour");
	characterC->AddCharacter(this);
	
	SetSize(32, 36);
	SetFrames(3);
	SetSpeed(0.2f);
	SetHealth(50);
}