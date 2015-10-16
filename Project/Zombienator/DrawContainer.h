#ifndef DRAW_CONTAINER_H
#define DRAW_CONTAINER_H

#pragma once
#include "SDL.h"
#include "AbstractContainer.h"

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