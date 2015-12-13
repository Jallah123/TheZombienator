#pragma once
#include "DrawBehaviour.h"
class SimpleDrawBehaviour :
	public DrawBehaviour
{
public:
	SimpleDrawBehaviour();
	~SimpleDrawBehaviour();

	virtual void Draw(float dt, SDL_Renderer& ren, int XOffset, int YOffset) override;
};

