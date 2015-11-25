#pragma once
#include "Bullet.h"
class NormalBullet :
	public Bullet
{
private:
	SDL_Point* end = {};
	SDL_Point* begin = { };
public:
	NormalBullet();
	~NormalBullet();
	void CalculateEndPoint();
	SDL_Point* GetEndPoint() { return end; }
	SDL_Point* GetBeginPoint() { return begin; }
	void SetBeginPoint(SDL_Point* p) { begin = p; }
};

