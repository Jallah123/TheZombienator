#pragma once
#include "CollideBehaviour.h"
#include "CharacterContainer.h"

class NormalBulletCollideBehaviour :
	public CollideBehaviour
{
public:
	NormalBulletCollideBehaviour() {};
	~NormalBulletCollideBehaviour();
	virtual void Collide(float dt) override;
};

