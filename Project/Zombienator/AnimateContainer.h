#pragma once
#include "AbstractContainer.h"

class AnimateContainer :
	public AbstractContainer
{
public:
	AnimateContainer();
	~AnimateContainer();

	void Animate(float dt);
};