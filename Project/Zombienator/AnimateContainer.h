#ifndef AMIMATE_CONTAINER_H
#define AMIMATE_CONTAINER_H

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

#endif