#pragma once
#include "DrawBehaviour.h"

class HudDrawbehaviour :
	public DrawBehaviour
{
public:
	HudDrawbehaviour();
	void Draw(float dt, SDL_Renderer & ren, int XOffset, int YOffset);
	~HudDrawbehaviour();
};

