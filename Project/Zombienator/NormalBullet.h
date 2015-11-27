#pragma once
#include "Bullet.h"
class NormalBullet :
	public Bullet
{
private:
	SDL_Point* end = {};
	SDL_Point* begin = { };
	const int xFrontOffset = 7;
	const int yFrontOffset = 8;

	const int xSideOffset = 3;
	const int ySideOffset = 5;
public:
	NormalBullet();
	~NormalBullet();
	virtual void SetBehaviours() override;

	
	void CalculateEndPoint();
	SDL_Point* GetEndPoint() { return end; }
	SDL_Point* GetBeginPoint();
	void SetBeginPoint(SDL_Point* p) { begin = p; }

};

