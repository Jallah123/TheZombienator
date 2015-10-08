#include "AbstractContainer.h"
#pragma once
class MoveContainer : public AbstractContainer
{
public:
	MoveContainer();
	~MoveContainer();

	void Move();
};

