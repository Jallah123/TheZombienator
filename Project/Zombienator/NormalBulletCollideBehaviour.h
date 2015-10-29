#pragma once
#include "CollideBehaviour.h"
#include "CharacterContainer.h"

class NormalBulletCollideBehaviour :
	public CollideBehaviour
{
public:
	NormalBulletCollideBehaviour() {};
	~NormalBulletCollideBehaviour();
	virtual bool Collide(float dt) override;
};

