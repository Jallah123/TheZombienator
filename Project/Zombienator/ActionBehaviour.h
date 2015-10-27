#pragma once
#include "Behaviour.h"
class ActionBehaviour :
	public Behaviour
{
protected:
	char action;
public:
	ActionBehaviour();
	virtual ~ActionBehaviour();

	virtual void Update(float dt) = 0;
	char GetAction() { return this->action; }
};

