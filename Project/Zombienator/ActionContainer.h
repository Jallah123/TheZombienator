#pragma once
#include "AbstractContainer.h"
class InputContainer;
class ActionContainer
	: public AbstractContainer
{
private:
	InputContainer* inputContainer = nullptr;
	
public:
	ActionContainer();
	~ActionContainer();

	void Update(float dt);
	
};

