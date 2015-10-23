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
	Character* c = dynamic_cast<Character*>(gameObject);
	int frames = c->GetFrames();

	if (frames == 0) return;
	//Do casting
	
	Uint32 sprite = (ticks / 100) % frames;
	
	//get source rect
	SDL_Rect srcR = c->GetSourceRect();
	int width = c->GetWidth();
	int height = c->GetHeight();
	//Animate
	srcR.x = sprite * width;
	srcR.y = 0;
	//Set source rect
	c->SetSourceRect(srcR);
}
