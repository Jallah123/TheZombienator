#ifndef AMIMATE_CONTAINER_H
#define AMIMATE_CONTAINER_H
#include "AbstractContainer.h"
#pragma once
class Behaviour;

class AnimateContainer :
	public AbstractContainer
{
public:
	AnimateContainer();
	~AnimateContainer();

	virtual void Register() override;
};

#endif