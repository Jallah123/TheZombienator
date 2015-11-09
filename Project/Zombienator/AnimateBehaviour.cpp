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
	int frames = c->GetFrames();

	if (frames == 0) return;
	
	Uint32 sprite = (ticks / 100) % frames;
	//Direction::SOUTH  == 0;//UP
	//Direction::EAST == 1;//RIGHT
	//Direction::NORTH == 2;//DOWN
	//Direction::WEST == 3;//LEFT5

	//get source rect
	SDL_Rect srcR = c->GetSourceRect();
	if (c->GetMoveDir() != Direction::NONE) {
		int width = c->GetWidth();
		int height = c->GetHeight();

		//Animate
		int col = (sprite * width);
		int row = (height * c->GetLookDir());
		srcR.x = col;
		srcR.y = row;
	}
	//Set source rect
	c->SetSourceRect(srcR);
}
