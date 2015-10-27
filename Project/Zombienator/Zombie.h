#pragma once
#include "Character.h"

class AnimateContainer;
class DrawContainer;
class MoveContainer;

class Zombie :
	public Character
{
private:
	Character* target = nullptr;//Mike||Arnold
public:
	Zombie();
	~Zombie();
	void Init(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, ActionContainer* actionC, SDL_Renderer* ren);

	void SetTarget(Character* c) { this->target = c; }
	Character* GetTarget() { return this->target; }
};

