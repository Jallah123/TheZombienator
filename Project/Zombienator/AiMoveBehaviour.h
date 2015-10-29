#pragma once
#include "Behaviour.h"
class AiMoveBehaviour :
	public MoveBehaviour
{
public:
	AiMoveBehaviour();
	~AiMoveBehaviour();

	virtual void Move(float dt) override;
};

