#pragma once
#include "Behaviour.h"
class DrawBehaviour : public Behaviour
{
public:
	DrawBehaviour();
	virtual ~DrawBehaviour();
	
	//Use Draw
	virtual void Draw(float dt, SDL_Renderer& ren) = 0;
};