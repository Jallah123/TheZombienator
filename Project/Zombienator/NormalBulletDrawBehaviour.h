#pragma once
#include "DrawBehaviour.h"

class NormalBulletDrawBehaviour :
	public DrawBehaviour
{
public:
	NormalBulletDrawBehaviour();
	~NormalBulletDrawBehaviour();
	virtual void Draw(float dt, SDL_Renderer& ren) override;
};

