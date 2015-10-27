#pragma once
#include "ActionBehaviour.h"
class ShootActionBehaviour :
	public ActionBehaviour
{
public:
	ShootActionBehaviour();
	~ShootActionBehaviour();

	virtual void Update(float dt) override;
};

