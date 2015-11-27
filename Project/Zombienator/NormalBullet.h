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
	virtual void SetBehaviours() override;

	
	void CalculateEndPoint();
	SDL_Point* GetEndPoint() { return end; }
	SDL_Point* GetBeginPoint();
	void SetBeginPoint(SDL_Point* p) { begin = p; }

};

