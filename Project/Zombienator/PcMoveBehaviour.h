#pragma once
#include "MoveBehaviour.h"
class PcMoveBehaviour
	: public MoveBehaviour
{
public:
	PcMoveBehaviour();
	~PcMoveBehaviour();

	virtual void Move(float dt) override;
};

