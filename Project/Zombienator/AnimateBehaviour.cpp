#pragma once
#include "AnimateBehaviour.h"
#include "Character.h"
#include <iostream>


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

	timeSinceLastFrameSwap += dt;
	if (timeSinceLastFrameSwap > animationSpeed) {

		currentFrame++;
		timeSinceLastFrameSwap = 0.0f;

		//Get source rect
		SDL_Rect srcR = c->GetSourceRect();
		if (c->GetMoveDir() != Direction::NONE) {
			int width = c->GetWidth();
			int height = c->GetHeight();

			//Animate
			int col = (currentFrame * width);
			int row = (height * c->GetLookDir());
			srcR.x = col;
			srcR.y = row;
		}
		if (currentFrame == frames - 1) {
			currentFrame = 0;
		}

		//Set source rect
		c->SetSourceRect(srcR);
	}
}
