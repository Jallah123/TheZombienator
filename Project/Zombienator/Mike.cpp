#include "Mike.h"



Mike::Mike()
{
}

void Mike::Init(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, SDL_Renderer* ren)
{
	this->SetContainers(drawC, animC, moveC);
	SetDrawBehaviour("DrawBehaviour");
	SetAnimateBehaviour("AnimateBehaviour");
	SetMoveBehaviour("MoveBehaviour");
	SetImage("assets/images/spritesheets/Boy1.png", *ren);
	SetSize(32, 38);
	SetFrames(3);
}


Mike::~Mike()
{
}
