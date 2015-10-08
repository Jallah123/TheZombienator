#include "AbstractContainer.h"
#pragma once
class CollideContainer : public AbstractContainer
{
public:
	CollideContainer();
	~CollideContainer();

	void Collide();
};

