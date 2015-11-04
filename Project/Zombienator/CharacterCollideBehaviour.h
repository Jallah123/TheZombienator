#pragma once
#include "CollideBehaviour.h"
class CharacterCollideBehaviour :
	public CollideBehaviour
{
public:
	CharacterCollideBehaviour();
	~CharacterCollideBehaviour();

	virtual bool Collide(float dt) override;

};

