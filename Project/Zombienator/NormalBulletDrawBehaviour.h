#pragma once
#include "DrawBehaviour.h"

class NormalBulletDrawBehaviour :
	public DrawBehaviour
{
private:
	const int maxLength = 1280;
	const int offsetX = 7;
	const int offsetY = 5;
	SDL_Rect rect;
public:
	NormalBulletDrawBehaviour();
	~NormalBulletDrawBehaviour();
	virtual void Draw(float dt, SDL_Renderer& ren) override;
};

