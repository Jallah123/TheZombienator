#ifndef DRAW_CONTAINER_H
#define DRAW_CONTAINER_H
#include "SDL.h"
#include "AbstractContainer.h"
#pragma once

class AbstractContainer;
class DrawContainer :
	public AbstractContainer
{
public:
	DrawContainer();
	~DrawContainer();

	void Draw(float dt, SDL_Renderer& ren);
};

#endif