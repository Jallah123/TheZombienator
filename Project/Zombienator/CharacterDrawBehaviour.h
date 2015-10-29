#pragma once
#include "DrawBehaviour.h"
class CharacterDrawBehaviour :
	public DrawBehaviour
{
public:
	CharacterDrawBehaviour();
	~CharacterDrawBehaviour();
	virtual void Draw(float dt, SDL_Renderer& ren) override;
};

