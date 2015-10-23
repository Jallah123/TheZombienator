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
	//MoveDirection::SOUTH  == 0;//UP
	//MoveDirection::EAST == 1;//RIGHT
	//MoveDirection::NORTH == 2;//DOWN
	//MoveDirection::WEST == 3;//LEFT

	//get source rect
	SDL_Rect srcR = c->GetSourceRect();
	int width = c->GetWidth();
	int height = c->GetHeight();

	//Animate
	int col = c->GetMoveDir() == MoveDirection::NONE ? width : (sprite * width);
	int row = c->GetMoveDir() == MoveDirection::NONE ? 0 : (height * c->GetMoveDir());//Still frame
	srcR.x = col;
	srcR.y = row;

	//Set source rect
	c->SetSourceRect(srcR);
}
