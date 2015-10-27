#include "Zombie.h"



Zombie::Zombie() : Character() {}


Zombie::~Zombie()
{
}


void Zombie::Init(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, SDL_Renderer* ren)
{
	//Zombie doesn't have input from the InputContainer
	this->SetContainers(drawC, animC, moveC, nullptr);
	SetDrawBehaviour("DrawBehaviour");
	SetAnimateBehaviour("AnimateBehaviour");
	SetMoveBehaviour("AiMoveBehaviour");
	SetImage("assets/images/spritesheets/1zombie.png", *ren);
	SetSize(32, 36);
	SetFrames(3);
	SetSpeed(0.5f);
}