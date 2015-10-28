#pragma once
#include "AbstractContainer.h"
class CollideContainer :
	public AbstractContainer
{
public:
	CollideContainer();
	~CollideContainer();

	void Collide(float dt);
};

