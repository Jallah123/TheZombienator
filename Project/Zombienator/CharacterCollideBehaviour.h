#pragma once
#include "CollideBehaviour.h"
class CharacterCollideBehaviour :
	public CollideBehaviour
{
public:
	CharacterCollideBehaviour();
	~CharacterCollideBehaviour();

	virtual void Collide(float dt) override;
	void Stop(GameObject* c, SDL_Rect* rect);
};

