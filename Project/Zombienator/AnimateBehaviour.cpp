#pragma once
#include "AnimateBehaviour.h"
#include "Character.h"



AnimateBehaviour::AnimateBehaviour() : Behaviour()
{
}


AnimateBehaviour::~AnimateBehaviour()
{
}

void AnimateBehaviour::Animate(float dt, int ticks)
{
	if (!this->gameObject) return;
	//Do casting
	Character* c = dynamic_cast<Character*>(gameObject);
	Uint32 sprite = (ticks / 100) % c->GetFrames();
	
	//get source rect
	SDL_Rect srcR = c->GetSourceRect();
	//Animate
	srcR.w = sprite * c->GetWidth();
	//Set source rect
	c->SetSourceRect(srcR);
}
