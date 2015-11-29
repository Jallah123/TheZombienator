#pragma once
#include "AbstractContainer.h"
class InputContainer;
class ActionContainer
	: public AbstractContainer
{
public:
	ActionContainer();
	~ActionContainer();

	void Update(float dt);
	
};

