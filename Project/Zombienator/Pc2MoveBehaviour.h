#pragma once
#include "MoveBehaviour.h"
class Pc2MoveBehaviour
	: public MoveBehaviour
{
public:
	Pc2MoveBehaviour();
	~Pc2MoveBehaviour();

	virtual void Move(float dt) override;
};

