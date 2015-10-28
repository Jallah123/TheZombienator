#pragma once
#include "Behaviour.h"
class Character;

class CollideBehaviour :
	public Behaviour
{
public:
	CollideBehaviour();
	virtual ~CollideBehaviour();
	virtual bool Collide(float dt) = 0;
};

