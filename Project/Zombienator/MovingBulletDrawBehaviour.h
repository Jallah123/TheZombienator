#pragma once
#include "DrawBehaviour.h"
class MovingBulletDrawBehaviour :
	public DrawBehaviour
{
private:
	SDL_Rect rect = { 0,0,10,10 };
public:
	MovingBulletDrawBehaviour();
	~MovingBulletDrawBehaviour();


	virtual void Draw(float dt, SDL_Renderer& ren, int XOffset, int YOffset) override;
};

