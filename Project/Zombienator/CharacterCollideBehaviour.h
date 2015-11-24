#pragma once
#include "CollideBehaviour.h"
class CharacterCollideBehaviour :
	public CollideBehaviour
{
public:
	CharacterCollideBehaviour();
	~CharacterCollideBehaviour();

	virtual void Collide(float dt) override;
};

