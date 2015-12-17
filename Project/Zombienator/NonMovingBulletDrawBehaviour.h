#pragma once
#include "DrawBehaviour.h"

class NonMovingBulletDrawBehaviour :
	public DrawBehaviour
{
private:
	const int offsetX = 7;
	const int offsetY = 5;
	SDL_Rect rect;
public:
	NonMovingBulletDrawBehaviour();
	~NonMovingBulletDrawBehaviour();
	virtual void Draw(float dt, SDL_Renderer& ren, int XOffset, int YOffset) override;
};

