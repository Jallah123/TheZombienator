#ifndef DRAW_BEHAVIOUR_H
#define DRAW_BEHAVIOUR_H
#include "Behaviour.h"

#pragma once

class Behaviour;
class DrawBehaviour : public Behaviour
{
public:
	DrawBehaviour();
	~DrawBehaviour();
	
	//Use Draw
	void Draw(float dt, SDL_Renderer& ren);
};

#endif