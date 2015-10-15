#ifndef AMIMATE_CONTAINER_H
#define AMIMATE_CONTAINER_H
#include "AbstractContainer.h"
#pragma once

class AnimateContainer :
	public AbstractContainer
{
public:
	AnimateContainer();
	~AnimateContainer();

	void Animate(float dt);
};

#endif