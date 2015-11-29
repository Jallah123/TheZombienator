#pragma once
#include "ActionBehaviour.h"
class ShootActionBehaviour :
	public ActionBehaviour
{
private:
	float elapsedTime = 0;
	float maxElapsed = 1000;
public:
	ShootActionBehaviour();
	~ShootActionBehaviour();

	virtual void Update(float dt) override;
};

