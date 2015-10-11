#pragma once
#include "AbstractContainer.h"
class DrawContainer :
	public AbstractContainer
{
public:
	DrawContainer();
	~DrawContainer();

	virtual void Register() override;
	void Draw(SDL_Renderer& ren);
};

