#include "Zombie.h"



Zombie::Zombie()
{
}


Zombie::~Zombie()
{
}


void Zombie::Init(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, SDL_Renderer* ren)
{
	this->SetContainers(drawC, animC, moveC);
	SetDrawBehaviour("DrawBehaviour");
	SetAnimateBehaviour("AnimateBehaviour");
	SetMoveBehaviour("MoveBehaviour");
	SetImage("assets/images/spritesheets/1zombie.png", *ren);
	SetSize(32, 36);
	SetFrames(3);
}