#pragma once
#include "Character.h"

class AnimateContainer;
class DrawContainer;
class MoveContainer;
class CharacterContainer;

class Zombie :
	public Character
{
private:
	Character* target = nullptr;//Mike||Arnold
public:
	Zombie();
	~Zombie();
	void Init(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, ActionContainer* actionC,CharacterContainer* characterC, SDL_Renderer* ren);

	void SetTarget(Character* c) { this->target = c; }
	Character* GetTarget() { return this->target; }
};

