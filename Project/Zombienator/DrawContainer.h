#pragma once
#include "SDL.h"
#include "AbstractContainer.h"

class DrawContainer :
	public AbstractContainer
{
public:
	DrawContainer();
	~DrawContainer();

	void Draw(float dt, SDL_Renderer& ren, int XOffset, int YOffset);
	void Sort_zIndex();
};
